#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(){
	char str_inp[20],result[10];
	int length;
	printf("Enter your password : ");
	scanf("%s",str_inp);
	for(length=0;str_inp[length]!='\0';++length);
	printf("Length of your password is %d\n",length);
	int lower,upper,digit,symbol;
	int x = check_char(str_inp,&lower,&upper,&digit,&symbol);
	//printf("%d",x);
	if ((length<=6))
		strcpy(result,"instantly");
	else if (length==7){
		switch(x){
			case 1:
				strcpy(result,"4 sec");
				break;
			case 2:
				strcpy(result,"2 sec");
				break;
			case 3:
				strcpy(result,"1 sec");
				break;
			case 4:
				strcpy(result,"instantly");
				break;
			case 5:
				strcpy(result,"instantly");
				break;
		}
		//kalai
	}
	else if (length==8){
		switch(x){
			case 1:
				strcpy(result,"5 min");
				break;
			case 2:
				strcpy(result,"2 min");
				break;
			case 3:
				strcpy(result,"28 sec");
				break;
			case 4:
				strcpy(result,"instantly");
				break;
			case 5:
				strcpy(result,"instantly");
				break;
		}
	}
	else if (length==9){
		switch(x){
			case 1:
				strcpy(result,"6 hrs");
				break;
			case 2:
				strcpy(result,"2 hrs");
				break;
			case 3:
				strcpy(result,"24 min");
				break;
			case 4:
				strcpy(result,"3 sec");
				break;
			case 5:
				strcpy(result,"instantly");
				break;
		}
	}
	else if (length==10){
		switch(x){
			case 1:
				strcpy(result,"2 weeks");
				break;
			case 2:
				strcpy(result,"5 days");
				break;
			case 3:
				strcpy(result,"21 hrs");
				break;
			case 4:
				strcpy(result,"1 min");
				break;
			case 5:
				strcpy(result,"instantly");
				break;
		}
	}
	else if (length==11){
		switch(x){
			case 1:
				strcpy(result,"3 years");
				break;
			case 2:
				strcpy(result,"10 months");
				break;
			case 3:
				strcpy(result,"1 months");
				break;
			case 4:
				strcpy(result,"32 mins");
				break;
			case 5:
				strcpy(result,"instantly");
				break;
		}
	}
	else if (length==12){
		switch(x){
			case 1:
				strcpy(result,"226 years");
				break;
			case 2:
				strcpy(result,"53 years");
				break;
			case 3:
				strcpy(result,"6 years");
				break;
			case 4:
				strcpy(result,"14 hrs");
				break;
			case 5:
				strcpy(result,"1 sec");
				break;
		}
	}
	else if (length==13){
		switch(x){
			case 1:
				strcpy(result,"15k years");
				break;
			case 2:
				strcpy(result,"3k years");
				break;
			case 3:
				strcpy(result,"332 years");
				break;
			case 4:
				strcpy(result,"2 weeks");
				break;
			case 5:
				strcpy(result,"5 sec");
				break;
		}
	}	
	else if (length==14){
		
		switch(x){
			case 1:
				strcpy(result,"1m years");
				break;
			case 2:
				strcpy(result,"202k years");
				break;
			case 3:
				strcpy(result,"17k years");
				break;
			case 4:
				strcpy(result,"1 years");
				break;
			case 5:
				strcpy(result,"52 sec");
				break;
		}
	}
	else if (length==15){
		switch(x){
			case 1:
				strcpy(result,"77m years");
				break;
			case 2:
				strcpy(result,"12m years");
				break;
			case 3:
				strcpy(result,"898k years");
				break;
			case 4:
				strcpy(result,"27 years");
				break;
			case 5:
				strcpy(result,"9 mins");
				break;
		}
	}
	else if (length==16){
		switch(x){
			case 1:
				strcpy(result,"5bn years");
				break;
			case 2:
				strcpy(result,"779m years");
				break;
			case 3:
				strcpy(result,"46m years");
				break;
			case 4:
				strcpy(result,"713 years");
				break;
			case 5:
				strcpy(result,"1 hrs");
				break;
		}
	}
	else if (length==17){
		switch(x){
			case 1:
				strcpy(result,"380bn years");
				break;
			case 2:
				strcpy(result,"48bn years");
				break;
			case 3:
				strcpy(result,"2bn years");
				break;
			case 4:
				strcpy(result,"18k years");
				break;
			case 5:
				strcpy(result,"14 hrs");
				break;
		}
	}
	else if (length==18){
		switch(x){
			case 1:
				strcpy(result,"26tn years");
				break;
			case 2:
				strcpy(result,"2tn years");
				break;
			case 3:
				strcpy(result,"126bn years");
				break;
			case 4:
				strcpy(result,"481k years");
				break;
			case 5:
				strcpy(result,"6 days");
				break;
		}
	}
	printf("This password brutforced %s",result);
		
}
int check_char(const char *str, int *hasLowercase, int *hasUppercase, int *hasDigit, int *hasSymbol) {
    *hasLowercase = 0;
    *hasUppercase = 0;
    *hasDigit = 0;
    *hasSymbol = 0;
    
    while (*str) {
        if (islower(*str)) {
            *hasLowercase = 1;
        } else if (isupper(*str)) {
            *hasUppercase = 1;
        } else if (isdigit(*str)) {
            *hasDigit = 1;
        } else {
            *hasSymbol = 1;
        }
        str++;
    }
    if((*hasLowercase)*(*hasUppercase)*(*hasDigit)+(*hasSymbol))
    	return 1;
    else if((*hasLowercase)*(*hasUppercase)*(*hasDigit))
    	return 2;
    else if((*hasLowercase)*(*hasUppercase))
    	return 3;
    else if((*hasLowercase))
    	return 4;
    else if(*hasDigit)
    	return 5;
}
