#include <linux/latencytop.h>
#include <linux/sched.h>
#include <linux/cpumask.h>
#include <linux/slab.h>
#include <linux/profile.h>
#include <linux/interrupt.h>
#include <linux/mempolicy.h>
#include <linux/migrate.h>
#include <linux/task_work.h>

#include <trace/events/sched.h>
#include <linux/sysfs.h>
#include <linux/vmalloc.h>
#ifdef CONFIG_HMP_FREQUENCY_INVARIANT_SCALE
/* Include cpufreq header to add a notifier so that cpu frequency
 * scaling can track the current CPU frequency
 */
#include <linux/cpufreq.h>
#endif /* CONFIG_HMP_FREQUENCY_INVARIANT_SCALE */
#ifdef CONFIG_SCHED_HMP
#include <linux/cpuidle.h>
#endif

#include "sched.h"


static void init_mycfs_rq(struct mycfs_rq *mycfs_rq){
}

static inline struct mycfs_rq *mycfs_rq_of(struct sched_entity *se)
{
	struct task_struct *p = task_of(se);
	struct rq *rq = task_rq(p);
	return &rq->mycfs;
}


static void _dequeue_entity(struct mycfs_rq *mycfs_rq, struct sched_entity *se){
				
	curr_pos += 1;		
}

struct void
set_next_entity(struct mycfs_rq, struct sched_entity *se){
	
	if(se->on_rq){
		_dequeue_entity(mycfs_rq, se);
	}
}

static void set_curr_task_mycfs(struct rq *rq)
{
	struct sched_entity *se = &rq->curr->se;
	printk("On rq:%d\n", se->on_rq);
	for_each_sched_entity(se) {
		struct mycfs_rq *mycfs_rq = mycfs_rq_of(se);
		set_next_entity(mycfs_rq, se);
	}
}

static void 
enqueue_entity(struct mycfs_rq *cfs_rq, struct sched_entity *se, int flags){

}

static void
enqueue_task_mycfs(struct rq *rq, struct task_struct *p, int flags)
{
	struct mycfs_rq *mycfs_rq;
	struct sched_entity *se = &p->se;
	
	if(!(se->on_rq)){
		cfs_rq = cfs_rq_of(se);
		enqueue_entity(cfs_rq, se, flags);
		cfs_rq->h_nr_running++;
		//This flag is used for waking up a sleeping task	
		flags = ENQUEUE_WAKEUP;
	}
	//TO BE COMPLETED
}

static void dequeue_task_mycfs(struct rq *rq, struct task_struct *p, int flags)
{
	printk(KERN_ALERT "DQ ANKIT KULSHRESTHA\n");
}

static void yield_task_mycfs(struct rq *rq)
{
	printk(KERN_ALERT "YIELD TASK ANKIT KULSHRESTHA\n");
}

static bool yield_to_task_mycfs(struct rq *rq, struct task_struct *p, bool preempt)
{
	printk(KERN_ALERT "YIELD TO TASK ANKIT KULSHRESTHA\n");
}

static void check_preempt_wakeup(struct rq *rq, struct task_struct *p, int wake_flags){}
static struct task_struct *pick_next_task_mycfs(struct rq *rq)
{
	printk(KERN_ALERT "TASK STRUCT ANKIT KULSHRESTHA\n");
}

static void put_prev_task_mycfs(struct rq *rq, struct task_struct *prev)
{
	printk(KERN_ALERT "PUT PREV ANKIT KULSHRESTHA\n");
}


struct 
static void task_tick_mycfs(struct rq *rq, struct task_struct *curr, int queued)
{
	printk(KERN_ALERT "TASK TICK ANKIT KULSHRESTHA\n");
}

static void task_fork_mycfs(struct task_struct *p)
{
	printk(KERN_ALERT "TASK FORK ANKIT KULSHRESTHA\n");
}

static void
prio_changed_mycfs(struct rq *rq, struct task_struct *p, int oldprio)
{
	printk(KERN_ALERT "PRIO ANKIT KULSHRESTHA\n");
}

static void switched_from_mycfs(struct rq *rq, struct task_struct *p)
{
	printk(KERN_ALERT "SWITCHED ANKIT KULSHRESTHA\n");
}

static void switched_to_mycfs(struct rq *rq, struct task_struct *p)
{
	printk(KERN_ALERT "SWITCHED TO ANKIT KULSHRESTHA\n");
}

static unsigned int get_rr_interval_mycfs(struct rq *rq, struct task_struct *task)
{
	printk(KERN_ALERT "GET RR ANKIT KULSHRESTHA\n");
}

/*
 * All the scheduling class methods:
 */

const struct sched_class mycfs_sched_class = {
	.next			= &idle_sched_class,
	.enqueue_task		= enqueue_task_mycfs,
	.dequeue_task		= dequeue_task_mycfs,
	.yield_task		= yield_task_mycfs,
	.yield_to_task		= yield_to_task_mycfs,

	.check_preempt_curr	= check_preempt_wakeup,

	.pick_next_task		= pick_next_task_mycfs,
	.put_prev_task		= put_prev_task_mycfs,

//#ifdef CONFIG_SMP
//	.select_task_rq		= select_task_rq_mycfs,
//#ifdef CONFIG_mycfs_GROUP_SCHED
//	.migrate_task_rq	= migrate_task_rq_mycfs,
//#endif
//	.rq_online		= rq_online_mycfs,
//	.rq_offline		= rq_offline_mycfs,
//
//	.task_waking		= task_waking_mycfs,
//#endif

	.set_curr_task          = set_curr_task_mycfs,
	.task_tick		= task_tick_mycfs,
	.task_fork		= task_fork_mycfs,

	.prio_changed		= prio_changed_mycfs,
	.switched_from		= switched_from_mycfs,
	.switched_to		= switched_to_mycfs,

	.get_rr_interval	= get_rr_interval_mycfs,

//#ifdef CONFIG_mycfs_GROUP_SCHED
//	.task_move_group	= task_move_group_mycfs,
//#endif

};
