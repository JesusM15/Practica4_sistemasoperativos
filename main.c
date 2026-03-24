#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    int pid = 0;
    
    printf("Soy el padre de todos los siguientes procesos, los cuales realizan distintas tareas.\n");
    printf("Soy Nodo P, mi PID es: #%d\n", getpid());
    fflush(stdout);

    pid = fork();

    if(pid == 0){
        // NODO A 
        printf("Soy Nodo A, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
        fflush(stdout);

        pid = fork();
        if(pid == 0){
            // NODO B
            printf("Soy Nodo B, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
            fflush(stdout);
            system("pwd");
            return 0; 
        }
        
        wait(NULL); 

        pid = fork();
        if(pid == 0){
            // NODO C 
            printf("Soy Nodo C, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
            fflush(stdout);
            system("ls");
            
            pid = fork();
            if(pid == 0){
                // NODO D 
                printf("Soy Nodo D, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
                fflush(stdout);
                system("ps");
                
                pid = fork();
                if (pid == 0){
                    // NODO E
                    printf("Soy Nodo E, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
                    fflush(stdout);
                    system("date");
                    return 0; 
                }
                
                wait(NULL);

                pid = fork();
                if(pid ==  0){
                    // NODO F 
                    printf("Soy Nodo F, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
                    fflush(stdout);
                    system("ps");
                    
                    pid = fork();
                    if(pid == 0){
                        // NODO G 
                        printf("Soy Nodo G, mi PID es: #%d y mi padre es: #%d\n", getpid(), getppid());
                        fflush(stdout);
                        system("touch estructura_procesos");
                        return 0; 
                    }

                    wait(NULL);
                    return 0; 
                }
                
                wait(NULL); 
                return 0; 
            }

            wait(NULL); 
            return 0; 
        }

        wait(NULL);
       
        printf("clear\n"); 
        return 0; 

    } else if(pid > 0){
        // NODO P
        wait(NULL); 
        printf("Todos los procesos han terminado\n");
    }

    return 0;
}

