#include "thread_hdr.h"
int interval, ticks;
void add_ready_thread(thread* ready_thread)
{
	// ��Ӧ�Ĵ���ʵ��
	ready_queue.push_back(ready_thread);
}

void schedule()
{
	// ��Ӧ�Ĵ���ʵ��
	if (current_thread != &idle_thread) {
		ready_queue.push_back(current_thread);
	}
	if (ready_queue.size() > 0) {
		current_thread = ready_queue.front();
		ready_queue.pop_front();
	}
	else
	{
		current_thread = &idle_thread;
	}
}

void current_thread_finished()
{
	// ʵ�ֵĴ���
	if (ready_queue.size() > 0) {
		current_thread = ready_queue.front();
		ready_queue.pop_front();
	}
	else {
		current_thread = &idle_thread;
	}
}

void current_thread_blocked()
{
	// ��Ӧ�Ĵ���ʵ��
	blocked_queue.push_back(current_thread);
	if (ready_queue.size() > 0) {
		current_thread = ready_queue.front();
		ready_queue.pop_front();
	}
	else
	{
		current_thread = &idle_thread;
	}
}

void notify()
{
	// ��Ӧ�Ĵ���ʵ��
	if (blocked_queue.size() > 0) {
		ready_queue.push_back(blocked_queue.front());
		blocked_queue.pop_front();
	}
}

void notify_all()
{
	// ��Ӧ�Ĵ���ʵ��
	while (blocked_queue.size() > 0) {
		notify();
	}
}

void on_clock()
{
	// ��Ӧ�Ĵ���ʵ��
	if (current_thread != &idle_thread) {
		if (current_thread->clock_times + interval >= ticks) {
			current_thread->clock_times = 0;
			schedule();
		}
		else {
			current_thread->clock_times += interval;
		}
	}
	else {
		schedule();
	}

}

void set_time_ticks(unsigned int ticks)
{
	// ��Ӧ�Ĵ���ʵ��
	::ticks = ticks;
}

void set_time_interval(unsigned int interval)
{
	// ��Ӧ�Ĵ���ʵ��
	::interval = interval;
}