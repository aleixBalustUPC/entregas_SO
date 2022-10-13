#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char peticion[100];
	char resultado[100];
	strcpy(peticion, "Paco/47/Pedrito/12/Martin/22/Juana/19");
	
	char *p = strtok(peticion, "/");
	char name[20];
	int edad;
	
	while (p != NULL){
		strcpy(name, p);
		p = strtok(NULL, "/");
		edad = atoi(p);
		if (edad > 18) {
			sprintf(resultado, "%s%s*%d-", resultado, name, edad);
		}
		p = strtok(NULL, "/");

	}
	resultado[strlen(resultado)-1] = '\0';
	printf("Output: %s", resultado);
	
	
/*FUNCION PARA DETECTAR PALINDROMOS, COMO COMENTARIO PORQUE NO LOGRO VER DONDE FALLA
	char nombre [10] = "SUGUS";
	int i = 0;
	int j = strlen(nombre) - 1;
	int cumple = 1;
	while (j > i){
		if (nombre[i] != nombre[j]){
			cumple = 0;
			break;
		}
		i = i +1;
		j = j - 1;
		
	};
	if (cumple == 1){
		printf("Es palindromo");
	}
	else
		printf("No lo es");
	*/
	return 0;;
	
	
}

