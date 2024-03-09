#include <stdio.h>
#include <string.h>
#include <math.h>

int Add(char hex1[], char hex2[], int add, int over, int length1, int length2) {
	add = hex1[length1] + hex2[length2];
	if(over == 49) {add ++;}
	return add;
}

int Over1(int add) {
	if(add >= 112) {return 49;}
	else {return 48;}
}

int Over2(int add) {
	if(add == 112 || add > 118) {return 49;}
	else {return 48;}
}

void wrote(char sonuc[], int length3) {
	printf("\n Sonuc : ");
	for(int i = 0; i < length3; i++) {if((58 > sonuc[i] && sonuc[i] > 47) || (71 > sonuc[i] && sonuc[i] > 64)) {printf("%c", sonuc[i]);}}
}

void writToArray(char sonuc[], char hex1[], char hex2[], int length1, int length2, int length3) {
	if(length1 > length2) {for(int i = length1; i >= 0; i--) {sonuc[i] = hex1[i];}}
	else if(length2 > length1) {for(int i = length2; i >= 0; i--) {sonuc[i] = hex2[i];}}
	length3 = strlen(sonuc);
	wrote(sonuc, length3);
}

int func1(char hex1[], char hex2[], int add, int length1, int length2) {
	if(add >= 112) {
		add -= 64;
		return add;
	}
	else if(112 > add && add > 105) {
		if(add == 106) {return 65;}
		else if (add == 107) {return 66;}
		else if(add == 108) {return 67;}
		else if(add == 109) {return 68;}
		else if(add == 110) {return 69;} 
		else {return 70;}
	}
	else if(106 > add && add > 57) {
		add -= 48;
		return add;
	}
}

int func2(char hex1[], char hex2[], int add, int length1, int length2) {
    if(129 > add && add > 118) {
		if(add == 128) {return 57;}
		else if(add == 127) {return 56;}
		else if(add == 126) {return 55;}
		else if(add == 125) {return 54;}
		else if(add == 124) {return 53;}
		else if(add == 123) {return 52;}
		else if(add == 122) {return 51;}
		else if(add == 121) {return 50;}
		else if(add == 120) {return 49;}
		else if(add == 119) {return 48;}
	}
	else if(119 > add && add >112) {
		if(add == 118) {return 70;}
		else if(add == 117) {return 69;}
		else if(add == 116) {return 68;}
		else if(add == 115) {return 67;}
		else if(add == 114) {return 66;}
		else if(add == 113) {return 65;}
	}
	else if(add == 112) {
		add -= 64;
		return add;
	}
}

int func3(char hex1[], char hex2[], int add, int length1, int length2) {
    if(136 > add && add > 129) {
		if(add == 130) {return 52;}
		else if(add == 131) {return 53;}
		else if(add == 132) {return 54;}
		else if(add == 133) {return 55;}
		else if(add == 134) {return 56;}
		else if(add == 135) {return 57;}
	}
	else if(142 > add && add > 135) {
		if(add == 141) {return 70;}
		else if(add == 140) {return 69;}
		else if(add == 139) {return 68;}
		else if(add == 138) {return 67;}
		else if(add == 137) {return 66;}
		else if(add == 136) {return 65;}
	}
}

int main() {
    char hex1[150];
    char hex2[150];
    char sonuc[170];
    
    printf("\n 1. Hexadecimal degeri giriniz : ");
    gets(hex1);
    printf("\n 2. Hexadecimal degeri giriniz : ");
    gets(hex2);
    int length1 = strlen(hex1), length2 = strlen(hex2), add = 0, over = 48, length3 = 0;
    length1 --;
    length2 --;

    if(length1 > length2) {length3 = length1;}
	else {length3 = length2;}
	while(1) {
		if((47 < hex1[length1] && hex1[length1] < 58) && (47 < hex2[length2] && hex2[length2] < 58)) {
    		add = Add(hex1, hex2, add, over, length1, length2);
			over = Over1(add);
			add = func1(hex1, hex2, add, length1, length2);
			sonuc[length3] = add;
		}
		else if(((47 < hex1[length1] && hex1[length1] < 58) && (64 < hex2[length2] && hex2[length2] < 71)) || 
		((47 < hex2[length2] && hex2[length2] < 58) && (64 < hex1[length1] && hex1[length1] < 71))){
			add = Add(hex1, hex2, add, over, length1, length2);
			over = Over2(add);
			add = func2(hex1, hex2, add, length1, length2);
			
			if(length1 == length2 && add == 48) {length3 ++;}
			sonuc[length3] = add;
		}
		else if((64 < hex1[length1] && hex1[length1] < 71) && (64 < hex2[length2] && hex2[length2] < 71)) {
			add = Add(hex1, hex2, add, over, length1, length2);
			over = 49;
			add = func3(hex1, hex2, add, length1, length2);
			sonuc[length3] = add;
		}
		length1 --;
	    length2 --;
		length3 --;
		if(length1 == (-1) || length2 == (-1)) {break;}
	}
	if(over == 49) {sonuc[length3] = 49;}
	writToArray(sonuc, hex1, hex2, length1, length2, length3);	
}
