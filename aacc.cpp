#include<stdio.h>
int substring(char shortstr[], char longstr[]);
int mint()
{

//}

///int substring(char shortstr[], char longstr[]){// xet tung gia tri trong 
    char *p1, *p2, *p3;
    p1 = "longstr";
    p2 = "shortstr";
    int i = 0, j = 0, flag = 0, lenShort = strlen(p1), lenLong = strlen(p2);

    if(lenShort > lenLong)// neu do dai ham trong may dai hon thi thoat
        return 0;
    for(i = 0; i < lenLong; i++){//cay tu 0 den do dai cua  xau ten 
        if(*p1 == *p2){//neu gia tri ben l s thi xay ra
            p3 = p1; printf("%c %c",p1,*p1);
        	for(j = 0; j < lenShort; j++){
           		if(*p3 == *p2){
                	p3++; p2++;// khi tim ra mot ki tu dong thi that ra 
            	}
                else break;
            	}
        	p2 = shortstr;//gai la gia tri p2

        	if(j == lenShort){//neu j = ls thi dau ra gia tri phu hop  
            flag = 1;
            }
        }

        p1++;
    }

    return flag;
}
