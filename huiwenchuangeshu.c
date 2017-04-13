#include "stdio.h"
#include "string.h"
#include "stdlib.h"
struct pos{
    int  num;   //计算出现的次数
    int  pos;   //记录出现的位置
    struct pos* next;
};

int get_order (char);
void insert (struct pos*,int);
void find_odd (struct pos *,int,int);

int tep_sum;
int main ()
{
    int num,i;
    int tep_pos;
    int length; ///每次记录的字符串的长度
    int order;
    int m,n,k;
    struct pos * tep1,*tep2;
    char str[1000];
    scanf("%d",&num);
    int result[num+1];
    for(i=1;i<=num;i++)
        result[i]=0;
    struct pos letter[37];      ///这是对应的每一个出现的字符的数组

    for(i=1;i<=num;i++){
        ///每一组数据都要对字母数组进行初始化
        for(m=1;m<=36;m++){
            letter[m].num=0;
            letter[m].next=NULL;
        }
    ///从0——9 以及 a——z
        scanf("%s",str);
        length=strlen(str);     ///取得这次处理的字符串的长度
        for(tep_pos=0;tep_pos<length;tep_pos++){
            order=get_order(str[tep_pos]);
            insert(&letter[order],tep_pos);
            letter[order].num++;
        }
        tep_sum=0;
        ///先开始求长度为奇数的回文子序列
        for(tep_pos=1;tep_pos<length-1;tep_pos++){
            //tep_sum=0;
            find_odd(letter,tep_pos,tep_pos);
            //result[i]+=tep_sum;
            //printf("%d\n",tep_sum);                         ///调试用***************************************************
        }
        for(m=1;m<=36;m++){
            if(letter[m].num>=2){
                for(n=1;n<=letter[m].num-1;n++){
                    tep1=&letter[m];
                    for(k=1;k<=n;k++){
                        tep1=tep1->next;
                    }
                    tep2=tep1->next;
                    while(tep2){
                        tep_sum++;
                        find_odd(letter,tep1->pos,tep2->pos);
                        tep2=tep2->next;
                    }
                }
                //printf("%d %c\n",tep_sum,'a'+m-11);                 ///调试用***************************************************
            }
        }
        result[i]=tep_sum+length;
    }
    for(i=1;i<=num;i++)
        printf("Case #%d: %d\n",i,result[i]);
    return 0;
}
int get_order (char c)
{
    int order;
    if(c>='0'&&c<='9')
        order=c-'0'+1;
    else if(c>='a'&&c<='z')
        order=c-'a'+11;
    return order;
}
void insert (struct pos* p,int pos)
{
    struct pos * tep ,* anew;
    anew=(struct pos*)malloc(sizeof(struct pos));
    anew->next=NULL;
    anew->pos=pos;
    tep=p;
    while(tep->next)
    {
        tep=tep->next;
    }
    tep->next=anew;

}
void find_odd (struct pos *letter,int start,int end)
{
    int i;
    //int m,n;
    struct pos  *pfront,*pend;
    struct pos  *tep1,  *tep2;
    for(i=1;i<=36;i++){
        if(letter[i].num>=2){
            pfront=letter[i].next;
            while(pfront&&pfront->pos<start){///这里要注意当为空的时候你怎么可以对一颗空指针进行求被容的行为！要利用短路效应将他短路掉
                pfront=pfront->next;
            }
            ///pfront 是停在了极限的后一个
            pend=pfront;
            while(pend&&pend->pos<=end){///这里必须把pend放在前面，利用了短路的性质避免了空指针的引用
                pend=pend->next;
            }
            ///pend 是停在了极限
            if(pfront!=letter[i].next&&pend!=NULL){///y因为pront是停在了极限的后一个，所以这里用的是正确的
                tep1=letter[i].next;
                //for(tep1=letter[i].next;tep1->next!=pfront;tep1=tep1->next)
                while(tep1!=pfront){
                    tep2=pend;
                    while(tep2){
                        tep_sum++;
                        find_odd(letter,tep1->pos,tep2->pos);
                        tep2=tep2->next;
                    }
                    tep1=tep1->next;
                }
            }
        }
    }
}
