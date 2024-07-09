#include <stdio.h>
#include <string.h>

/* 個人データ */
typedef struct{
	char name[100];
	double height;
	double weight;
}member;

/* double型の値交換（*xと*yの値を交換） */
void swap(double *x,double *y)
{
	double z = *x;
    *x = *y;
    *y = z;
}

/* char[]の値交換（sx[]とsy[]の値を交換） */
void swaps(char sx[],char sy[])
{
    char temp[100];
    memcpy(temp,sx,100);
    memcpy(sx,sy,100);
    memcpy(sy,temp,100);
}

int main(void)
{
	FILE *fp;
	member ma[10];
	char str[10];
	int i = 0;
	char filename[60];

	scanf("%s",filename);

	//ファイルを開く
	//ファイルがオープンできなかったらtrueとなる
	if((fp = fopen(filename,"r")) == NULL)
		printf("ファイルをオープンできません。\n");
	else{
		//ファイルがオープンできた時の処理
		int j;
		int k;	
		
		while(fscanf(fp, "%s%lf%lf",ma[i].name,&(ma[i].height),&(ma[i].weight)) == 3){
			printf("%-10s %5.1f %5.1f\n",ma[i].name,ma[i].height,ma[i].weight);
			i++;
		}
        
		//ソートを行う
        for(k = 0; k < i-1; k++){
            for(j = k+1; j < i; j++){
                if(ma[j].height < ma[k].height){
                swap(&(ma[j].height),&(ma[k].height));
                swap(&(ma[j].weight),&(ma[k].weight));
                swaps(ma[j].name,ma[k].name);
                }
            }
        }
		//ソート結果を表示
		printf("----------SortResult----------\n");
		for(i=0;i<j;i++)
			printf("%-10s %5.1f %5.1f\n",ma[i].name,ma[i].height,ma[i].weight);
		fclose(fp);
	}

	return (0);
}