#include <math.h>
#include <stdio.h>
int main( )
{
    int t,x,y,num,tmp,m,n;

    scanf("%d",&t);
    while( t-- )
    {
        scanf("%d%d",&x,&y );
        num = y-x;
        if( !num )
            printf("0\n");
        else
        {
            tmp = sqrt( num );
            n = pow(tmp , 2 );
            m = ( pow( tmp+1 , 2 )-pow(tmp , 2 ) )/2;

            if( num-n > m )
                printf("%d\n",2*( tmp+1 )-1 );
            else if( num-n == 0  )
                printf("%d\n",2*tmp-1);
            else
                printf("%d\n",2*tmp);
        }
    }
    return 0;
}
