#ifndef __SHORTEST__REMAINING__TIME
#define __SHORTEST__REMAINING__TIME




#include "./Process.h"
#include "./SortingFunction.h"
#include "./PrintTable.h"

/**
 * [srt_calculate_time SRT ]
 * @param p   
 * @param len 
 */
void srt_calculate_time(Process *p, int len)
{
	int i;
	
	int current_time = 0;
	
	int total_burst_time = 0;
	
	int shortest_remain_time;
	
	int k = 0;
	


	int *remain_burst_time = (int *)malloc(sizeof(int) * len);

	int *count = (int *)malloc(sizeof(int) * len);


	for (i = 0; i < len; i++)
	{
		count[i] = 0;
		
		remain_burst_time[i] = p[i].burst;
		
		total_burst_time += p[i].burst;
		
	}


	while (current_time < total_burst_time)
	{
		shortest_remain_time = INT_MAX;
		

	
		if (current_time <= p[len - 1].arrive_time)
		{
		
			for (i = 0; i < len; i++)
			{
			
				if ((p[i].completed == FALSE)
						&& (p[i].arrive_time <= current_time)
							&& (shortest_remain_time > remain_burst_time[i]))
				{
					shortest_remain_time = remain_burst_time[i];
					
					k = i;
					
				}
			}
		}

	
		else
		{
		
			for (i = 0; i < len; i++)
			{
			
				if ((p[i].completed == FALSE)
						&& (shortest_remain_time > remain_burst_time[i]))
				{
					shortest_remain_time = remain_burst_time[i];
					
					k = i;
					
				}
			}
		}

	
		if (count[k] == 0)
		{
			count[k]++;
			
			p[k].response_time = current_time;
			
		}

		remain_burst_time[k]--;
		
		current_time++;
		

	
		if (remain_burst_time[k] == 0)
		{
			p[k].completed = TRUE;
			
			p[k].waiting_time = current_time - p[k].burst - p[k].arrive_time;
			
			p[k].return_time = current_time;
			
		}
	}


	free(count);
	free(remain_burst_time);
}

/**
 * [srt_print_gantt_chart ]
 * @param p   
 * @param len 
 */
void srt_print_gantt_chart(Process *p, int len)
{
	int i;
	int total_burst_time = 0;
	int current_time = 0, previous_time;
	
	int k, pre_k = 0;
	
	int shortest_remain_time, num;
	

	int *count = (int *)malloc(sizeof(int) * len);
	int *remain_burst_time = (int *)malloc(sizeof(int) * len);

	for (i = 0; i < len; i++)
	{
		remain_burst_time[i] = p[i].burst;
		total_burst_time += p[i].burst;
		p[i].completed = FALSE;
		count[i] = 0;
	}

	printf("\t ");


	while (current_time < total_burst_time)
	{
		shortest_remain_time = INT_MAX;

		if (current_time <= p[len - 1].arrive_time)
		{
			for (i = 0; i < len; i++)
			{
				if ((p[i].completed == FALSE)
						&& (p[i].arrive_time <= current_time))
				{
					if (shortest_remain_time > remain_burst_time[i])
					{
						shortest_remain_time = remain_burst_time[i];
						k = i;
					}
				}
			}
		}

		else
		{
			for (i = 0; i < len; i++)
			{
				if (p[i].completed == FALSE)
				{
					if (shortest_remain_time > remain_burst_time[i])
					{
						shortest_remain_time = remain_burst_time[i];
						k = i;
					}
				}
			}
		}

	
		if (pre_k != k)
			printf(" ");
			

		printf("--");
		remain_burst_time[k]--;
		current_time++;
		pre_k = k;
		

		if (remain_burst_time[k] == 0)
			p[k].completed = TRUE;
	}

	for (i = 0; i < len; i++)
	{
		remain_burst_time[i] = p[i].burst;
		p[i].completed = FALSE;
	}

	current_time = 0;
	printf("\n\t|");


	while (current_time <= total_burst_time)
	{
	
		if (current_time != total_burst_time)
		{
			shortest_remain_time = INT_MAX;

			if (current_time <= p[len - 1].arrive_time)
			{
				for (i = 0; i < len; i++)
				{
					if ((p[i].completed == FALSE)
						&& (p[i].arrive_time <= current_time)
							&& (shortest_remain_time > remain_burst_time[i]))
					{
						shortest_remain_time = remain_burst_time[i];
						k = i;
					}
				}
			}

			else
			{
				for (i = 0; i < len; i++)
				{
					if ((p[i].completed == FALSE)
						&& (shortest_remain_time > remain_burst_time[i]))
					{
						shortest_remain_time = remain_burst_time[i];
						k = i;
					}
				}
			}

			if (current_time == 0)
			{
				count[k]++;
				printf("  ");
			}

			else
			{
			
				if (pre_k != k)
				{
					num = count[pre_k] + 1;
					
					count[pre_k] = 0;
					
					count[k]++;
					

				
					for (i = 0; i < num; i++)
						printf("\b");

				
					printf("%2s", p[pre_k].id);

				
					for (i = 0; i < num - 2; i++)
						printf(" ");

					printf("|  ");
				}

			
				else
				{
					count[k]++;
					

					printf("  ");
					
				}
			}

			pre_k = k;
			remain_burst_time[k]--;
			current_time++;

			if (remain_burst_time[k] == 0)
				p[k].completed = TRUE;
		}

	
		else
		{
		
			for (i = 0; i < count[pre_k] + 1; i++)
				printf("\b");

		
			printf("%2s", p[k].id);

		
			for (i = 0; i < count[pre_k] - 1; i++)
				printf(" ");

			break;
			
		}
	}

	for (i = 0; i < len; i++)
	{
		remain_burst_time[i] = p[i].burst;
		p[i].completed = FALSE;
	}

	current_time = 0;
	printf("|\n\t");


	while (current_time < total_burst_time)
	{
		shortest_remain_time = INT_MAX;

		if (current_time <= p[len - 1].arrive_time)
		{
			for (i = 0; i < len; i++)
			{
				if ((p[i].completed == FALSE)
					&& (p[i].arrive_time <= current_time)
						&& (shortest_remain_time > remain_burst_time[i]))
				{
					shortest_remain_time = remain_burst_time[i];
					k = i;
				}
			}
		}

		else
		{
			for (i = 0; i < len; i++)
			{
				if ((p[i].completed == FALSE)
					&& (shortest_remain_time > remain_burst_time[i]))
				{
					shortest_remain_time = remain_burst_time[i];
					k = i;
				}
			}
		}

		if (pre_k != k)
			printf(" ");

		printf("--");

		remain_burst_time[k]--;
		current_time++;
		pre_k = k;

		if (remain_burst_time[k] == 0)
			p[k].completed = TRUE;
	}

	for (i = 0; i < len; i++)
	{
		remain_burst_time[i] = p[i].burst;
		p[i].completed = FALSE;
	}

	current_time = 0;
	printf("\n\t");


	while (current_time <= total_burst_time)
	{
		if (total_burst_time != current_time)
		{
			shortest_remain_time = INT_MAX;

			if (current_time <= p[len - 1].arrive_time)
			{
				for (i = 0; i < len; i++)
				{
					if ((p[i].completed == FALSE)
						&& (p[i].arrive_time <= current_time)
							&& (shortest_remain_time > remain_burst_time[i]))
					{
						shortest_remain_time = remain_burst_time[i];
						k = i;
					}
				}
			}

			else
			{
				for (i = 0; i < len; i++)
				{
					if ((p[i].completed == FALSE)
						&& (shortest_remain_time > remain_burst_time[i]))
					{
						shortest_remain_time = remain_burst_time[i];
						k = i;
					}
				}
			}


			if (pre_k != k)
			{
				for (i = 0; i < num && current_time != 0; i++)
					printf("  ");

				if (current_time != 0)
					printf(" ");

				printf("%-2d", current_time);
				num = 0;

				previous_time = current_time;
			}

			else
				num++;

			remain_burst_time[k]--;
			current_time++;
			pre_k = k;

			if (remain_burst_time[k] == 0)
				p[k].completed = TRUE;
		}

		else
		{
			for (i = 0; i < current_time - previous_time - 1; i++)
				printf("  ");
			printf(" ");

			printf("%-2d", current_time);

			break;
		}
	}

	printf("\n");


	free(count);
	free(remain_burst_time);
}

/**
 * [SRT SRT ]
 * @param p 
 * @param len 
 */
void SRT(Process *p, int len)
{
	int i;
	
	int total_waiting_time = 0;
	
	int total_turnaround_time = 0;
	
	int total_response_time = 0;
	

	process_init(p, len);
	

	merge_sort_by_arrive_time(p, 0, len);
	

	srt_calculate_time(p, len);
	


	for (i = 0; i < len; i++)
	{
		p[i].turnaround_time = p[i].return_time - p[i].arrive_time;
		
		total_waiting_time += p[i].waiting_time;
		
		total_turnaround_time += p[i].turnaround_time;
		
		total_response_time += p[i].response_time;
		
	}

	printf("\tShortest Remaining Time Algorithm\n\n");

	srt_print_gantt_chart(p, len);
	


	printf("\n\tAverage Waiting Time     : %-2.2lf\n", (double)total_waiting_time / (double)len);
	printf("\tAverage Turnaround Time  : %-2.2lf\n", (double)total_turnaround_time / (double)len);
	printf("\tAverage Response Time    : %-2.2lf\n\n", (double)total_response_time / (double)len);

	print_table(p, len);
	
}

#endif