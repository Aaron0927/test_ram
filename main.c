#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h> //for getcwd
#include <sys/stat.h>//for cmkdir
#include <fcntl.h>//for access

#include <sys/mman.h>

#include <sys/types.h>
#include <dirent.h> // dir options
#include "main.h"


int persist(void) {
    Segment *seg = (Segment*)malloc(sizeof(Segment));
    seg->segleter = (Seglet*)malloc(sizeof(Seglet));
    seg->segleter->objector = (Object*)malloc(sizeof(Object));
    FILE *fp;
    if((fp = fopen("/home/zhangchengfei/workspace/test_ram/1.1428340272.ram", "wb"))==NULL)
    {
    }
    int totalSize = sizeof(Segment) + (sizeof(Seglet) + sizeof(Object)) * 1;
    fwrite(seg, totalSize,1,fp); /* 成块写入文件*/
    if (fflush(fp) == 0) {

    }
    fclose(fp);



    FILE *fp2;

    if ((fp2 = fopen("1.1428340272.ram", "rb")) == NULL) {
       }
Segment *head = (Segment *)malloc(sizeof(Segment));
            head->segleter = (Seglet *)malloc(sizeof(Seglet));
            head->segleter->objector = (Object *)malloc(sizeof(Object));

    int total = (sizeof(Seglet) + sizeof(Object)) + sizeof(Segment);
    if (fread(head, total, 1, fp2) == 0) {
    }
    fclose(fp2);
    return 0;
}


























typedef struct stu{ /*定义结构体*/
    char name[20];
    float score;
    struct stu *next;
}Stu;

typedef struct cla {
    Stu *student;
    int n;
} Class;
void writefile() {
    FILE *fp1;
    Class *class01 = (Class *)malloc(sizeof(Class));
    class01->n = 3;
    Stu *stu1 = (Stu *)malloc(sizeof(Stu));
    Stu *stu2 = (Stu *)malloc(sizeof(Stu));
    char *name1 = "zhangchengfei";
    strcpy(stu1->name, name1);
    stu1->score = 99;
    class01->student = stu1;
    char name2[20] = "zhangchengfei";
    memcpy(stu2->name, name2, 20);
    stu2->score = 98;

    class01->student->next = stu2;
    if((fp1=fopen("10.107.19.8:1000:1","wb"))==NULL)
    { /*以二进制只写方式打开文件*/
        printf("cannot open file");
        exit(0);
    }
    int i = sizeof(Class);
    int j = sizeof(Stu);
    fwrite(class01,i + j * 2,1,fp1); /* 成块写入文件*/

    fflush(fp1);
    fclose(fp1);
    //free(stu1);
    //free(stu2);
    //free(class01);
}

void readfile() {
    FILE *fp2;

    Class *class02 = (Class *)malloc(sizeof(Class));
    Stu *stu1 = (Stu *)malloc(sizeof(Stu));
    Stu *stu2 = (Stu *)malloc(sizeof(Stu));
    class02->student = stu1;
    stu1->next = stu2;
        if((fp2=fopen("10.107.19.8:1000:1","rb"))==NULL)
        { /*重新以二进制只写打开文件*/
            printf("cannot open file");
            exit(0);
        }
        int i = sizeof(Class);
        int j = sizeof(Stu);
        fread(class02,i + j * 2,1,fp2); /* 从文件成块读*/
        printf("%d++++++++++++++++%s+++%f\n",class02->n,class02->student->next->name,class02->student->next->score);
        fclose(fp2);

}

int main(void)
{
/*
    char buf[128];
    getcwd(buf, sizeof(buf));
    strcat(buf, "/backup");
    //mkdir(buf ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if(chdir(buf) == 0) {
        printf("success!\n");
    }
    if(chdir("/home/zhangchengfei/workspace/ramcube/ramcube_config/backup/127.0.0.1.11114/") == 0) {
        printf("success!\n");
    }
    strcat(buf, "/127.0.0.1");
    mkdir(buf ,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

     //scan_file("/home/zhangchengfei/workspace/test/test/backup");

    if((access("backup", F_OK)) == -1) {
        fprintf(stderr, "directory not exist!\n");
    } else {
        printf("directory exist!\n");
        scanfile("/home/zhangchengfei/workspace/test/test/backup");
    }
*/

persist();
    //char *buf = (char *)malloc(128);
    //getcwd(buf, 128); //get current directory
    //appendToSegment("set key1 0 0 12\r\nzhangchengfe\r\n127.0.0.1:11114\r\n");
    //readFile("/home/zhangchengfei/workspace/ramcube/ramcube_config/backup/127.0.0.1.11114/","1.1428304037.ram");
    //writefile();
    //readfile();
    return 0;


}








































