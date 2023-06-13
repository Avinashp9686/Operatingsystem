#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t pid;
    pid=vfork();
    if(pid==-1){
        perror("vfork");
        return 1;
    } else if (pid==0)
    {
        printf("child process:Hello,i'm the child!\n");
        printf("child process:My pid is %d\n",getpid());
        printf("child process :My parent's pid is %d\n",getppid());
        _exit(0);
    } else{
        printf("Parent process:Hello,I'm the parent!\n");
        printf("Parent process:My pid is %d\n",getpid());
        printf("Parent process:My child's pid is %d\n",pid);
        int status;
        waitpid(pid,&status,0);
        if(WIFEXITED(status)){
            printf("Parent process:child process terminated abnormally\n");
        }
    }
    return 0;
}