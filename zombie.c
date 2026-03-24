#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid = fork();

    if(pid > 0){
        //PADRE
        printf("Padre: (PID: #%d) durmiendo...\n", getpid());
        sleep(120); 
    } else if(pid == 0){
        printf("Soy el Nodo Hijo mi PID es: #%d\n", getpid());
        return 0;
    }
    return 0;
}