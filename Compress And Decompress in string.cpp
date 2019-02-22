#include<stdio.h>
#include<string.h>
void compression(char str[])
{
    int i=0;
    char ch=str[0];
    int j=0;
    char c='0';
    while(str[i]!='\0')
    {
        if(ch==str[i])
        {
            c++;
        }
            //inword=0;
        else
        {
            str[j]=ch;
            j++;
            str[j]=(char)c;
            j++;
            ch=str[i];
            c='1';
        }
        i++;
    }
    str[j]=ch;
    j++;
    str[j]=c;
    j++;
    str[j]='\0';
}
void decompression(char str[])
{
    int i=1;
    char ch=str[0];
    int j=0,length=0;
    while(str[i]!='\0')
    {
        if(i%2==1)
        {
            length=length+(str[i]-'0');
        }
        i++;
    }
    str[length]='\0';
    j=length-1;
    i--;
    while(length!=0)
    {
        int c=0;
        c=c+(str[i]-'0');
        char ch=str[i-1];
        while(c!=0)
        {
            str[length-1]=ch;
            length--;
            c--;
        }
       i=i-2;
    }
}
int main() 
{
    char str[100];
    scanf("%[^\n]s ",str);
    puts(str);
    compression(str);
    puts(str);
    decompression(str);
    puts(str);
}
