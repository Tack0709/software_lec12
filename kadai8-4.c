#include <stdio.h>
#include <string.h>

/* 個人データ */
typedef struct {
  char name[100];
  double height;
  double weight;
} Member;

/* double型の値交換（*xと*yの値を交換） */
void swap_double(double *x, double *y) {
  double z = *x;
  *x = *y;
  *y = z;
}

/* char[]の値交換（sx[]とsy[]の値を交換） */
void swap_name(char sx[], char sy[]) {
  char temp[100];
  memcpy(temp, sx, 100);
  memcpy(sx, sy, 100);
  memcpy(sy, temp, 100);
}

int main(void) {
  FILE *fp;
  Member data[10];
  char str[10];
  int num = 0;
  char filename[60];

  scanf("%s", filename);

  //ファイルを開く
  //ファイルがオープンできなかったらtrueとなる
  if ((fp = fopen(filename, "r")) == NULL)
    printf("ファイルをオープンできません。\n");
  else {
    //ファイルがオープンできた時の処理

    while (fscanf(fp, "%s%lf%lf", data[num].name, &(data[num].height),
                  &(data[num].weight)) == 3) {
      printf("%-10s %5.1f %5.1f\n", data[num].name, data[num].height,
             data[num].weight);
      num++;
    }

    //ソートを行う
    for (int k = 0; k < num - 1; k++) {
      for (int j = k + 1; j < num; j++) {
        if (data[j].height < data[k].height) {
          swap_double(&(data[j].height), &(data[k].height));
          swap_double(&(data[j].weight), &(data[k].weight));
          swap_name(data[j].name, data[k].name);
        }
      }
    }
    //ソート結果を表示
    printf("----------SortResult----------\n");
    for (int i = 0; i < num; i++)
      printf("%-10s %5.1f %5.1f\n", data[i].name, data[i].height,
             data[i].weight);
    fclose(fp);
  }

  return (0);
}
