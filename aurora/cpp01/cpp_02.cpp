//
// Created by Administrator on 2019/2/1.
//
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


/*
 操作系统任务调度问题。操作系统任务分为系统任务和用户任务两种。其中，系统任务的优先级 < 50，用户任务的优先级 >= 50且 <= 255。
 优先级大于255的为非法任务，应予以剔除。现有一任务队列task[]，长度为n，task中的元素值表示任务的优先级，数值越小，优先级越高。
 函数scheduler实现如下功能，将task[] 中的任务按照系统任务、用户任务依次存放到 system_task[] 数组和 user_task[] 数组
 中（数组中元素的值是任务在task[] 数组中的下标），并且优先级高的任务排在前面，数组元素为-1表示结束。

 例如：task[] = {0, 30, 155, 1, 80, 300, 170, 40, 99}    system_task[] = {0, 3, 1, 7, -1}    user_task[] = {4, 8, 2, 6, -1}
*/


void schedule() {
    map<int, int> W;

    int count = 9, i, j = 0, k = 0;

    int *task = new int(count);
    int tmp[9] = {0, 30, 155, 1, 80, 300, 170, 40, 99};
    task = tmp;
//    task = &tmp[0];

    int *system_task = new int(count);
    int *user_task = new int(count);

    for (i = 0; i < count; i++) {
        if (task[i] < 50) {
            system_task[j++] = task[i];
            W.insert(make_pair(task[i], i));
        }
        if (task[i] >= 50 && task[i] <= 255) {
            user_task[k++] = task[i];
            W.insert(make_pair(task[i], i));
        }
    }

    sort(system_task, system_task + j);
    sort(user_task, user_task + k);

    for (i = 0; i < j; i++) {
        auto it = W.find(system_task[i]);
        system_task[i] = it->second;
        cout << system_task[i] << " ";
    }
    cout << "-1" << endl;

    for (i = 0; i < k; i++) {
        auto it = W.find(user_task[i]);
        user_task[i] = it->second;
        cout << user_task[i] << " ";
    }
    cout << "-1" << endl;

//    delete[] task;
    delete[] system_task;
    delete[] user_task;

}

void method() {
    map<int, string> t_map;
    auto key_1 = t_map.insert(make_pair(2, "very 7"));
    t_map.insert(make_pair(3, "yes 14"));
    t_map.insert(make_pair(4, "good 21"));
    t_map[5] = "eee 28";
    t_map[6] = 97;

    cout << sizeof(t_map) << " " << sizeof(key_1) << endl;
    int count = sizeof(t_map) / sizeof(make_pair(1, ""));
    cout << "count " << count << endl;

    auto it = t_map.find(6);
//    map<int, string>::iterator it = t_map.find(6);
    if (it != t_map.end()) {
        cout << it->first << " -> " << it->second << endl;
    } else {
        cout << "no value" << endl;
    }


}


int main() {

//    schedule();

//    method();

    int *task = new int[4]{3, 4, 5, 6};
    task[0] = 3;
    task[1] = 4;
    int *task_1 = new int(4);
    int tmp[4] = {};

    cout << task << endl;
    cout << task_1 << endl;
    cout << sizeof(task_1) << endl;
    cout << sizeof(task) << endl;
    cout << sizeof(tmp) << endl;
//    task = tmp; // 报错

    delete[] task;



    return 0;
}




