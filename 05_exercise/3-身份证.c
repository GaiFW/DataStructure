#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool runping(int nian)
{
    if(nian/4==0 && nian/100!=0 ||nian/400==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool run_yue(int  yue,int ri)
{
    switch(yue)
    {
        case 1:
            if(ri<=31)
            return 1;
        case 3:
            if(ri<=31)
            return 1;
        case 5:
            if(ri<=31)
            return 1;
        case 7:
            if(ri<=31)
            return 1;
        case 8:
            if(ri<=31)
            return 1;
        case 10:
            if(ri<=31)
            return 1;
        case 12:
            if(ri<=31)
            return 1;
        case 2:
            if(ri<=29)
            return 1;
        case 4:
            if(ri<=30)
            return 1;
        case 6:
            if(ri<=30)
            return 1;
        case 11:
            if(ri<=30)
            return 1;
    }
}

bool ping_yue(int yue,int ri)
{
	switch(yue)
    {
        case 1:
            if(ri<=31)
            return 1;
        case 3:
            if(ri<=31)
            return 1;
        case 5:
            if(ri<=31)
            return 1;
        case 7:
            if(ri<=31)
            return 1;
        case 8:
            if(ri<=31)
            return 1;
        case 10:
            if(ri<=31)
            return 1;
        case 12:
            if(ri<=31)
            return 1;
        case 2:
            if(ri<=28)
            return 1;
        case 4:
            if(ri<=30)
            return 1;
        case 6:
            if(ri<=30)
            return 1;
        case 11:
            if(ri<=30)
            return 1;
    }
}
//typedef unsigned long long type; 
void panduan(char* data)
{

    char guishu_str[6] = {};
    for(int i=0;i<6;i++)
    {
        guishu_str[i] = data[i];
    }
    int guishu_data = atoi(guishu_str);
    // printf("17data:%c---\n",data[17] );

    char birthday_str[9] = {};
    char nian_str[5] = {};
    char yue_str[4] = {};
    char ri_str[4] = {};
    for(int i=0;i<8;i++)
    {
        
        birthday_str[i] = data[6+i];
        if(i<=3)
        {
        	// printf("nian %c\n",data[6+i] );
            nian_str[i] = data[6+i];

        }
        else if(i<=5)
        {
            yue_str[i-4] = data[6+i];
        }
        else
        {
            ri_str[i-6] = data[6+i];
        }
    }
    long birthday_data = atol(birthday_str);
    int nian_data = atoi(nian_str);
    int yue_data = atoi(yue_str);
    int ri_data = atoi(ri_str);
    if(nian_data>1900)
    {
        if(runping(nian_data))
        {
            if(run_yue(yue_data,ri_data))
            {
            }
            else
            {
                printf("生日不合格\n");
            }
        }
        else
        {
            if(ping_yue(yue_data,ri_data))
            {
            }
            else
            {
                printf("生日不合格\n");
            }
        }
    }
    else
    {
        printf("年份不合格\n");
    }

    char shunxu_str[3] = {};
    for(int i=0;i<3;i++)
    {
        shunxu_str[i] = data[14+i];
    }
    int shuxu_data = atoi(shunxu_str);


    char jiaoyan =data[17];
    // printf("%c\n",jiaoyan );
    if(jiaoyan<='9'&&jiaoyan>='0'||jiaoyan=='X')
    {
    }
    else
    {
   	// printf("%c\n",jiaoyan );
    printf("校验码不合格!");
    }

}


int main()
{
    char id[19]={};
   printf("input you id:");
    fgets(id,sizeof(id),stdin);
    // char p[8] = "19960607";
  // long long  p_d = atol(id);
    // printf("%lld\n",p_d );

   panduan(id);

    return 0;


    return 0;
}

