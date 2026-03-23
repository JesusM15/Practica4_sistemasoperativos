#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    int pid = 0;
    int parentPID = 0;
    printf("Soy el padre de todos los siguientes procesos, los cuales realizan distintas tareas.\n");

    pid = fork();

    if(pid == 0){
        // Nodo A.
        printf("Soy Nodo A, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());

        pid = fork();
        if(pid > 0){
            // Nodo A
            pid = fork();
            
            if(pid == 0){
                // Nodo C
                printf("Soy Nodo C, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
                system("ls");
                pid = fork();

                if(pid == 0){
                    // Nodo D
                    printf("Soy Nodo D, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
                    system("ps");
                    pid = fork();
                    if (pid == 0){
                        //Nodo E
                        printf("Soy Nodo E, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
                        system("date");
                        wait(NULL);
                        return 0;
                    }
                    else if(pid > 0){
                        //Nodo D

                        pid = fork();
                        if(pid ==  0){
                            //Nodo F
                            printf("Soy Nodo F, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
                            system("ps");
                            pid = fork();
                            if(pid == 0){
                                // NOdo G
                                printf("Soy Nodo G, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
                                system("touch estructura_procesos");
                                wait(NULL);
                                return 0;
                            }

                            wait(NULL);
                            return 0;
                        }
                        
                     } 
                    wait(NULL);
                    wait(NULL);
                    return 0;
      
                }

                wait(NULL);
                return 0;
            } 

        } else if(pid == 0){
            //Nodo B
            printf("Soy Nodo B, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
            system("pwd");
            wait(NULL);
            return 0;
        }

        wait(NULL);
        wait(NULL);
        printf("Clear\n");
        return 0;

    } else if(pid > 0){
        // Nodo P
        wait(NULL);
        printf("Todos los procesos han terminado\n");
    }


    return 0;
}