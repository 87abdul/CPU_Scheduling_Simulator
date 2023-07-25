CPU Scheduling Algorithm Simulator
==================================
<br/>


##  [Abdul Rahman](https://github.com/87abdul)
<br/>

# The CPU Scheduling Simulator is a command-line based program developed in C that emulates various CPU scheduling algorithms used in modern operating systems.This simulator provides a valuable tool for understanding and comparing different scheduling strategies, allowing developers and system administrators to optimize the performance and efficiency of their systems.

## Key Features:

#### Scheduling Algorithms: The simulator supports several common CPU scheduling algorithms, including:

#### 1. First-Come, First-Served (FCFS): Processes are executed in the order they arrive.
#### 2. Shortest Job Next (SJN): The shortest job in the queue is given priority.
#### 3. Round Robin (RR): Processes are executed in a time-sliced manner to provide fair sharing of CPU time.
#### 4. Priority Scheduling: Processes with higher priorities are given preference.
#### 5. Multilevel Queue Scheduling: Processes are divided into different priority queues, each with its own scheduling algorithm.
#### 6. Process Management: Users can input details of individual processes, including their arrival time, burst time, and priority.                                                                                               The simulator then simulates the execution of these processes using the selected scheduling algorithm.

#### Visualization: The simulator provides visual output that displays the sequence of process execution and the resulting Gantt chart, giving users a clear understanding of the CPU scheduling process.

#### Performance Metrics: Upon completion of the simulation, the CPU Scheduling Simulator computes various performance metrics, such as average waiting time, turnaround time, and response time. These metrics allow users to evaluate and compare the effectiveness of different scheduling algorithms.

### How it Works:

#### User Input: 
Users provide the details of processes, the number of processes, and select the desired scheduling algorithm.

#### Simulation: 
The simulator simulates the execution of processes based on the chosen algorithm, considering factors like process arrival time, burst time, and priority.

#### Gantt Chart: 
The simulator generates a Gantt chart representing the sequence of process execution over time, providing a visual representation of the CPU scheduling process.

#### Performance Metrics: 
After simulation completion, the simulator calculates performance metrics, allowing users to assess the efficiency of the chosen scheduling algorithm.

### Benefits:

#### Educational Tool: 
The CPU Scheduling Simulator serves as an educational tool for understanding CPU scheduling algorithms and their impact on system performance.

#### Optimization: 
It aids developers and system administrators in selecting the most appropriate scheduling algorithm to optimize system performance.

#### Comparative Analysis: 
The simulator facilitates a comparative analysis of different scheduling strategies, helping users make informed decisions.

#### Practical Application: 
The insights gained from the simulator can be directly applied to real-world scenarios to enhance the performance of operating systems.

##### Overall, the CPU Scheduling Simulator in C is a powerful tool for gaining insights into CPU scheduling algorithms and making informed decisions to enhance system performance and resource utilization. It is a valuable addition to any learning environment or professional setting where CPU scheduling is a critical aspect of system management.
## Test Case
Quantum : 2

|PID|Arrive Time|Burst Time|Priority|
|:-:|:-:|:-:|:-:|
|P0|3|5|2
|P1|0|4|3|
|P2|1|1|2|
|P3|5|3|4|
|P4|3|7|3|
|P5|8|2|1|

<br/>

## FCFS (First Come First Served)
- <br/>
[FCFS](https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/CpuSchedulingAlgorithmsModule/FCFS.h)

- Test Image

> Test Case

<img src="https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/Test%20Image/FCFS1.PNG" width="700" height="auto">

<br/>

## SJF (Shortest Job First)
- <br/>
[SJF](https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/CpuSchedulingAlgorithmsModule/SJF.h)

- Test Image

> Test Case

<img src="https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/Test%20Image/SJF1.PNG" width="700" height="auto">

<br/>

## SRT (Shortest Remaining Time)
- <br/>
[SRT](https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/CpuSchedulingAlgorithmsModule/SRT.h)

- Test Image

> Test Case

<img src="https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/Test%20Image/SRT1.PNG" width="700" height="auto">

<br/>

## Non-Preemptive Priority Scheduling
- <br/>
[NPP](https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/CpuSchedulingAlgorithmsModule/NPPS.h)

- Test Image

> Test Case

<img src="https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/Test%20Image/NPPS1.PNG" width="700" height="auto">

<br/>

## Preemptive Priority Scheduling
- <br/>
[pp](https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/CpuSchedulingAlgorithmsModule/PPS.h)

- Test Image

> Test Case

<img src="https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/Test%20Image/PPS1.PNG" width="700" height="auto">

<br/>

## RR (Round Robin)
- <br/>
[RR](https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/CpuSchedulingAlgorithmsModule/RR.h)

- Test Image

> Test Case

<img src="https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/Test%20Image/RR1.PNG" width="700" height="auto">

<br/>

## HRN (Highest Response-Ratio Next)
- <br/>
[HRN](https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/CpuSchedulingAlgorithmsModule/HRN.h)

- Test Image
> Test Case

<img src="https://github.com/87abdul/CPU_Scheduling_Simulator/blob/main/Test%20Image/HRN1.PNG" width="700" height="auto">'

<br/>

## Contributor
- [Abdul Rahman](https://www.github.com/87abdul)
