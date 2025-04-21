#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int put_err(char *s1, char *s2)
{
	int i = 0;
	while(s1[i])//bocloi 3la s1 bach ta5od size 3ala 9bl write
		i++;
	write(2, s1, i);
	i = 0;
	while (s2[i]) //bocloi 3la s2 bach ta5od size 3ala 9bl write ila 7atiti "" empty string f s2 maghay tra walo 7it size ghay kon fih 0
		i++;
	write(2,s2, i);
	write(2, "\n", 1);
	return 1;
}

int exec(char **argv, char **env, int i)
{
	argv[i] = NULL;// argv[i] ghat koon fiha | or ; or NULL kan mchi dik l blasa o NULL bash s7bso l aray tma
	execve(argv[0], argv, env); // argv 5rb9na fiha ghi f child ya3ni lasliya mghay traliha walo
	put_err("error: cannot execute ", argv[0]);//error ila faylat
	return 1;
}

int main(int argc , char **argv, char **env)
{
	int fd0 = dup(0);//7it 7ana kan dupiw 0 fl parent ghan 7tajo hada bach nrj3o 0 kifma kan finma nl9aw ; ola NULL(end of argv)
	int fd[2];//ta3 pipe
	int i = 0;//ta3 while
	(void)argc;//3la9bl lfclags


	while (argv[i] && argv[i + 1])// ila madarch parameter may dir walo
	{
		argv = &argv[i + 1];//kan nskipiw executable name of dakchi li executina. 7na maghan allociw ma walo ghan b9a 5damin ghab argv d execve
		i = 0; //madam argv ghay tbadal 5as i tahaiya trja3 l zero (line li lfo9) 
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))//incremonti 3la l commonde
			i++;
		if (i != 0 && strcmp(argv[0], "cd") == 0)//cd ma3ando la input la output hanya dir lo bhal hok
		{
			if (i != 2)//5as darori 2 parametrat
				put_err("error: cd: bad arguments", "");
			else if (chdir(argv[1]) != 0)//ila chdir failat
				put_err("error: cd: cannot change directory to ", argv[1]);
		}
		else if (i != 0 && ( argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			int pid = fork();
			if (pid == 0)
			{
				exec(argv, env, i);//0 dupina fih wa7d lpipe 9bila (ghat chofha lta7t)
				return 1;
			}
			else
			{
				dup2(fd0, 0);//0 kan rj3oh kifma kan 7it ghat kon ; mn ba3d
				waitpid(pid , NULL, 2);//waiti 3la a5ir wa7d
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], 1);//dupi pipe fl 1 hadchit ghift childe ya3ni lparent l 1 dyalo ba9a ta3 stdout
				close(fd[1]);
				close(fd[0]);
				close(fd0);
				exec(argv, env, i);
				return 1;
			}
			else
			{
				dup2(fd[0], 0);//dupi pipe f 0 bach next i9ramn pipe hadi dernaha fl parent ya3ni ghay 5sna nrdoha l stdin 9bl man diro ;
				close(fd[1]);
				close(fd[0]);
			}
		}

	}
	close(fd0);
	return 0;
}