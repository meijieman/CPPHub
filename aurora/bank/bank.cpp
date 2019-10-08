//
// Created by Administrator on 2019/2/2.
//

/**
 * https://www.cnblogs.com/carsonzhu/p/5528901.html
 */

//#include "stdafx.h"
#include "bank.h"
#include <iostream>
#include <chrono>

using namespace std;


int main() {

    Bank bank;
    bank.Simulation();

    return 0;
}

Bank::Bank(int window, int close_time)
        : _queue_number(window), _close_time(close_time),
          _total_time(0), _customer_number(0) {

    _work_queue = new std::queue<QueueNode>[window];

    srand(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()));

}

Bank::~Bank() {
    delete[] _work_queue;
}

void Bank::OpenForDay() {
    _event_list.push_back({0, 0});
}

void Bank::CustomerArrived(Event *event) {

    ++_customer_number;

    int duration_time, inter_time;
    duration_time = rand() % 1800 + 1;
    inter_time = rand() % 600 + 1;

    int t = event->_occur_time + inter_time;
    if (t < _close_time) {
        _event_list.push_back({t, 0});
        SortEventList();
    }

    int i;
    i = FindShortestQueue();

    _work_queue[i].push({event->_occur_time, duration_time});
    cout << "添加顾客" << "duration_time " << duration_time << ", inter_time " << inter_time << endl;

    if (_work_queue[i].size() == 1) {
        _event_list.push_back({event->_occur_time + duration_time, i + 1});
        SortEventList();
    }
}

void Bank::CustomerDeparture(Event *event) {
    int i = event->_type - 1;
    QueueNode customer;

    customer = _work_queue[i].front();
    _work_queue[i].pop();

    _total_time += event->_occur_time - customer._arrival_time;
    cout << "顾客离开 _total_time " << _total_time << endl;

    if (!_work_queue[i].empty()) {
        customer = _work_queue[i].front();
        _event_list.push_back({customer._duration_time + event->_occur_time, i + 1});

        SortEventList();
    }
}

int Bank::FindShortestQueue() {
    int result = 0;
    for (int i = 0; i < _queue_number; ++i) {
        if (_work_queue[result].size() > _work_queue[i].size()) {
            result = i;
        }
    }

    return result;
}

void Bank::SortEventList() {
    _event_list.sort([](const Event &e1, const Event &e2) -> bool { return e1._occur_time < e2._occur_time; });
}

void Bank::Simulation() {
    OpenForDay();
    Event event;

    cout << "开始模拟" << endl;

    while (!_event_list.empty()) {
        event = _event_list.front();

        _event_list.pop_front();
        if (event._type == 0) {
            CustomerArrived(&event);
        } else {
            CustomerDeparture(&event);
        }
    }

    cout << "结束模拟" << endl;

    cout << "客户数：" << _customer_number << endl
         << "总逗留时间（小时）：" << (double) _total_time / 3600.0 << endl
         << "平均逗留时间（分钟）：" << (double) _total_time / (double) (_customer_number * 60) << endl;

}