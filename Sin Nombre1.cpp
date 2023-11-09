#include <stdio.h>

int main (){
	int num, renglon = 0, espacio = 0, coma = 0, end = 0, email_no = 0;
	char caracter;
	int Tabla[50][3000];
	
	FILE *file = fopen("emails.csv", "r");
	FILE *archivo = fopen("182238.txt", "w");
	if (archivo == NULL) { 
		perror("Error al crear el archivo"); 
		return 2; 
	}
	if (file== NULL) {
		perror("Error en la apertura del achivo");
		return 1;
	} //Desde aquí, todo bien ---------
	
	while (feof (file)==0){
		caracter = fgetc (file);
		
		
		fscanf (file, "%d", &num);
		if(caracter == '\n' && espacio == 1){
			renglon ++;
		}
		if(caracter == ' ')
			espacio = 1;
		if(caracter != ' ')
			espacio = 0;
	}
	
	email_no = 0;
	while (feof (file)==0 && end == 0) { //Imprime los titulos-------
		caracter = fgetc (file);
			
		if(email_no == 1){
			fprintf(archivo, "%c", caracter);
			
			if(coma == 0 && caracter == '\n'){
				end = 1;
			}
			coma = 0;
			if(caracter == ','){
				fprintf(archivo, "\n");
				coma = 1;
			}
		}
		if (caracter == '.')
			email_no = 2;
			
		if (email_no == 2 && caracter == ',')
			email_no = 1;
	}
	
	fclose(file);
	fclose(archivo);
	return 0;
}
