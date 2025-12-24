#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 1000

typedef struct {
    int id;         // 学号
    char name[50];  // 姓名
    int chinese;    // 语文成绩
    int math;       // 数学成绩
    int sum;        // 总成绩
} Student;

Student stu[MAX_STUDENTS]; // 学生数组
int n = 0;                 // 当前学生数量

void add(void); 
void qinkong(void);
void biaoti(void);
void showall(void);
void show(Student s[], int i);
void xiugai(void);
void search(void); 
void del(void);
void sort(void); 

int main(void) {
    int choice;
    do {
        system("cls");
        printf("\n ======== 学生成绩管理系统 ========\n");
        printf("||          1. 添加记录           ||\n");
        printf("||          2. 显示记录           ||\n");
        printf("||          3. 修改记录           ||\n");
        printf("||          4. 删除记录           ||\n");
        printf("||          5. 查找记录           ||\n");
        printf("||          6. 排序记录           ||\n");
        printf("||          0. 退出系统           ||\n");
        printf(" ==================================\n");
        printf("请选择(0~6): ");
        scanf("%d", &choice);
        
        switch(choice){
        	case 1:add();break;
        	case 2:showall();break;
        	case 3:xiugai();break;
        	case 4:del();break;
        	case 5:search();break;
        	case 6:sort();break;
            case 0: printf("\n感谢使用学生成绩管理系统！\n");
                    printf("本系统由5513宿舍全体成员开发\n");
                    printf("再见！\n");break; 
            default: printf("\n无效选择，请重新输入！\n");
        }
        if(choice != 0) {
            printf("\n按任意键返回主菜单...");
            qinkong(); // 清空缓冲区
            getchar(); // 等待用户按键
        }
    } while(choice != 0);
    
    return 0;
}

void qinkong(void) {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void biaoti(void) {
    printf("\n%-8s %-10s %-8s %-8s %-8s\n", 
           "学号", "姓名", "语文", "数学", "总分");
    printf("========================================\n");
}

void add(void) {
    char quit = 'Y';
    int id, i;
	do
	{
		printf("学号：");
		scanf("%d", &id);
		for (i = 0; i < n; i++)
		{
			if (id == stu[i].id)  //假如新学号等于数组中某生的学号
			{
				printf("此学号存在！\n");
				return;
			}
		}
		stu[i].id = id;
		printf("姓名：");
		scanf("%s", &stu[i].name);
		printf("语文成绩：");
		scanf("%d", &stu[i].chinese);
		printf("数学成绩：");
		scanf("%d", &stu[i].math);
		stu[i].sum = stu[i].chinese + stu[i].math;  //计算出总成绩
		n++;  //记录条数加1
		printf("是否继续添加?(Y/N)");
		scanf("\t%c", &quit);
    } while(quit == 'Y' || quit == 'y');
	
}

void show(Student s[],int i){
    printf("%-8d %-10s %-8d %-8d %-8d\n", 
           s[i].id, s[i].name, s[i].chinese, s[i].math, s[i].sum);
}

void showall(void){
	int i;
	if(n == 0) {
		printf("没有学生记录 \n");
		return;
	}
	biaoti();
	for (i = 0; i < n; i++)
	{
		show(stu,i);
	}
    printf("\n共 %d 名学生\n",n);
}

void search(void){
	int choice, id, i, found;
    char name[20];
    printf("请输入学号：");
        scanf("%d", &id);
        for(i = 0; i < n; i++) {
            if(stu[i].id == id) {
                biaoti();
                show(stu, i);
                return;
            }
        }
            printf("未找到学号为 %d 的学生！\n", id);
        return;       
}

void xiugai(void){
	int id,i;
	int ch,s;
	if(n == 0) {
		printf("没有学生记录 \n");
		return;
	}
    printf("请输入要修改的学生学号：");
    scanf("%d", &id);
	for (i = 0; i < n; i++)
	{
		if (stu[i].id == id)
		{
			getchar();    	          //提取并丢掉回车键
			printf("找到该生的记录，如下所示：\n");
			biaoti();             	          //显示记录的标题
			show(stu, i);  	          //显示数组stu中的第i条记录
			printf("是否修改?(Y/N)\n");
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				getchar();            //提取并丢掉回车键
				printf("姓名：");
				scanf("%s", &stu[i].name);
				printf("语文成绩：");
				scanf("%d", &stu[i].chinese);
				printf("数学成绩：");
				scanf("%d", &stu[i].math);
				stu[i].sum = stu[i].chinese + stu[i].math;  //计算出总成绩
				printf("修改完毕。\n");
			}
			return;
		}
	}
	printf("没有查询到该学生信息\n");
}

void del(void){
	int id,i;
	int ch,s;
	if(n == 0) {
		printf("没有学生记录 \n");
		return;
	}
    printf("请输入要删除的学生学号：");
    scanf("%d", &id);
for (i = 0; i < n; i++)
	{
		if (id == stu[i].id)
		{
			getchar();
			printf("找到该生的记录，如下所示：\n");
			biaoti();           			    //显示记录的标题
			show(stu, i);     			    //显示数组stu中的第i条记录
			printf("是否删除?(Y/N)\n");
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				for (; i < n; i++)
					stu[i] = stu[i + 1];	//被删除记录后面记录均前移一位
				n--;          				//记录总条数减1
				printf("删除成功！");
			}
			return;
		}
	}
}

void sort(void){
	int i,j;
	int choice,s;
	Student t;
    if(n == 0) {
        printf("没有学生记录！\n");
        return;
    }
        printf("请选择排序方法:\n");
    printf("1. 总分由高至低\n");
    printf("2. 总分由低至高\n");
    printf("3. 按学号排序\n");
    printf("请选择: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:  // 总分由高到低
            for(i = 0; i < n - 1; i++) {
                for(j = i + 1; j < n; j++) {
                    if(stu[i].sum < stu[j].sum) {
                        t = stu[i];
                        stu[i] = stu[j];
                        stu[j] = t;
                    }
                }
            }
            printf("已按总分从高到低排序！\n");
            break;
            
        case 2:  // 总分由低到高
            for(i = 0; i < n - 1; i++) {
                for(j = i + 1; j < n; j++) {
                    if(stu[i].sum > stu[j].sum) {
                        t = stu[i];
                        stu[i] = stu[j];
                        stu[j] = t;
                    }
                }
            }
            printf("已按总分从低到高排序！\n");
            break;
            
        case 3:  // 按学号排序
            for(i = 0; i < n - 1; i++) {
                for(j = i + 1; j < n; j++) {
                    if(stu[i].id > stu[j].id) {
                        t = stu[i];
                        stu[i] = stu[j];
                        stu[j] = t;
                    }
                }
            }
            printf("已按学号排序！\n");
            break;
            
        default:
            printf("无效选择！\n");
            return;
    }
    
    biaoti();
    for(i = 0; i < n; i++) {
        show(stu, i);
    }
}
//本程序由5513宿舍团队完成 