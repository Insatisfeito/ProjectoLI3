#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "utils.h"

char* readStr(char *ptr){
        char strBuffer[1024];
        fgets(strBuffer, 1023, stdin);
	return allocStr(ptr, strBuffer);
}


int readInt(){
	char c;
	int sinal=1, res=0;
	c=getchar();
	switch(c){
		case '-': sinal = -1;
		case '+': c=getchar();
			  break;
	}
	while( c != '\n' && res != INT_MAX){
		if( c >= '0' && c <= '9' ){
			res = res*10 + c - '0';
			c = getchar();
		}else{
			res = INT_MAX;
			clearInputBuffer();
		}
	}
	if( res != INT_MAX )
		res *= sinal;
	return res;
}
unsigned int readUInt(){
	char c;
	unsigned int res=0;
	c=getchar();
	switch(c){
            case '+': c=getchar();
                      break;
	}
	while( c != '\n' && res != INT_MAX){
		if( c >= '0' && c <= '9' ){
			res = res*10 + c - '0';
			c = getchar();
		}else{
			res = INT_MAX;
			clearInputBuffer();
		}
	}
	return res;
}

double readDouble(){
    double res;
    char strBuffer[128];
    char strDouble[128];
    char *ps = &strBuffer[0];
    char *pd = &strDouble[0];
    char ponto = 0;

    
    fgets(strBuffer, 127, stdin);
    
    if( *ps == '+' || *ps == '-' ){
        *pd = *ps;
        ps++;pd++;
    }

    while( *ps != '\n' && *ps != '\0' && ponto != 2){
        if( *ps >= '0' && *ps <= '9' ){
            *pd = *ps;
            pd++;ps++;
        }else if( (*ps == ',' || *ps == '.') && ponto == 0 ){
            ponto = 1;
            *pd = '.';
            ps++;pd++;
        }else{
            ponto = 2;
        }
    }

    *pd = '\0'; //terminar a string do double
    
    if( ponto == 2 ) return NAN; //se o que foi lido nao for um numero, faz return NAN.
    
    sscanf(strDouble, "%lf", &res);
    return res;
}