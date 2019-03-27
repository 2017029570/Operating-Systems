#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int makeprocess(char** tok, int cnt) {
		int status;
		for(int a=0;a<cnt;a++) {
				//parsing command by " ".
				char* tok2[100];
				char cpy[100];
				strcpy(cpy, tok[a]);
				int i=0;
				tok2[i] = strtok(cpy, " ");
				while(tok2[i] != NULL) {
						i++;
						tok2[i] = strtok(NULL," ");
				}
				tok2[i-1] = strtok(tok2[i-1],"\n");
				tok2[i] = NULL;
				pid_t pid;

				//make child process and execute command.
				if((pid = fork()) < 0) {
						perror("fork error\n");
						exit(1);
				}
				else if(pid == 0) {
						if(execvp(tok2[0],tok2)==-1) printf("Command not found.\n");
						exit(0);
				}
		}
		//parent process waits all of child process terminated.
		while(wait(&status)>0);
		
		return 0;
		
}

int main(int argc, char* argv[]) {
    if(argc > 1) {
		//reading batch file.
        FILE* fi = fopen(argv[1],"r");
        char command[100];
		
        while(fgets(command,100,fi)) {
			int cnt = 0;
			
			//parsing command by ";".
            char* tok[100];
			tok[cnt] = strtok(command,";");
            while(tok[cnt] != NULL) {
				cnt++;
                tok[cnt] = strtok(NULL,";");
			}
			//fork() and execvp().
			makeprocess(tok,cnt);
		}
	}

    else {
		char command[100] = "\0";
		while(1) {
				printf("prompt> ");

				fgets(command,100,stdin);
				
				//if command is "quit", then shell is terminated.
				if(strcmp(command,"quit\n")==0) break;

				//parsing command by ";".
				int cnt = 0;
				char* tok[100];
				tok[cnt] = strtok(command,";");
				while(tok[cnt] != NULL) {
						cnt++;
						tok[cnt] = strtok(NULL, ";");
				}
	
				//fork() and execvp().
				makeprocess(tok,cnt);
		}
	}
	return 0;
}
