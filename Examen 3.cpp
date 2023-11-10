#include <stdio.h>

int main (){
	int prev = 0, num3, num2, num1, numF, cont = 0, cont2 = 0;;
	int coma = 0, end = 0, email_no = 0;
	char caracter, hist1, hist2, hist3;
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
		caracter = fgetc(file);
		if(caracter == ','){
			cont2 ++;
		}
		if(!(caracter == ' ' || caracter == ',')){
			if(caracter == 'E' || caracter == 'm' || caracter == 'a' || caracter == 'i' || caracter == 'l'){
			}else{
				switch(prev){
					case 0:
						hist1 = caracter;
						break;
					case 1:
						hist2 = caracter;
						break;
					case 2:
						hist3 = caracter;
						break;
				}
				prev ++;
				cont ++;
			}
		} else{
			num3 = hist3 - '0';
			num2 = hist2 - '0'; num2 = num2 * 10;
			num1 = hist1 - '0'; num1 = num1 * 100;
			prev = 0;
			numF = num3 + num2 + num1;
			Tabla[cont][cont2] = numF;
		}
		if(caracter == ' '){
			if(caracter == 'E' || caracter == 'm' || caracter == 'a' || caracter == 'i' || caracter == 'l'){
			} else{
				cont ++;
				cont2 = 0;
			}
		}
	}
	fclose(file);
	
	for(int a = 0; a < 50; a++){
		for(int b = 0; b < 3000; b++){
			printf(" %d", Tabla[a][b]);
		}
		printf("\n");
	}
	
	FILE *file2 = fopen("emails.csv", "r");
	if (file2== NULL) {
		perror("Error en la apertura del achivo");
		return 3;
	}
	
	email_no = 0;
	while (feof (file2)==0 && end == 0) { //Imprime los titulos-------
		caracter = fgetc (file2);
			
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
	
	fclose(file2);
	fclose(archivo);
	return 0;
}
