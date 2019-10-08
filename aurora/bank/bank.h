//
// Created by Administrator on 2019/2/2.
//

#ifndef AURORA_BANK_H
#define AURORA_BANK_H

#include <queue>
#include <list>

struct Event{
    int _occur_time;
    int _type;

    bool operator<(const Event &rhs){
        return _occur_time < rhs._occur_time;
    }
};

struct QueueNode{
    int _arrival_time;
    int _duration_time;
};

class Bank{
public:
    explicit Bank(int window_number = 4, int close_time = 8 * 3600);
    ~Bank();
    void Simulation();

private:
    int _queue_number;
    int _close_time;
    int _total_time;
    int _customer_number;

    std::list<Event> _event_list;
    std::queue<QueueNode> *_work_queue;

    void OpenForDay();
    void CustomerArrived(Event *event);
    void CustomerDeparture(Event *event);

    int FindShortestQueue();
    void SortEventList();
};
#endif //AURORA_BANK_H
