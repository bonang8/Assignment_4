#include<iostream>
#include<fstream>
#include<string>
#include <limits>
#include "ListNode.h"
#include "GenQueue.h"
using namespace std;
float findMedianStudentWaitTime(int arr[], int size);
void sortArray(int *arr, int size);
bool allWindowIdle(int *arr_window, int size);
int main(int argc, const char * argv[])
{
  // readLine - a string that will be used to read from the given file.
  string readLine = "";
  // string that holds the fileName from the commandline input
  string fileName = argv[1];
  //file - is the stream object
  ifstream file;
  // keepTrackOfLine - keeps track of each line from the file
  int keepTrackOfLine = 1;

  // if there are less than 2 command line arguments, then its invalid
  if(argc < 2)
  {
    cout << "invalid command line arguments" << endl;
  }

  // holds a number from the list
  int numOfWindows = 0;
  // student waitTime in Queue or time they exited the queue
  int waitTime = 0;
  // student time entered queue
  int studentTimeEnteredQueue = 0;
  // clockTick - clock tick
  int clockTick = 0;
  int numOfStudents = 0;
  string line = "";
  int recordNumber = 1;
  // ptr to window array
  int *ptr_windows = 0;
  DoublyLinkedList<Student> *studentRecords = new DoublyLinkedList<Student>();
 // Diag
  cout << endl;
  // open the file
  file.open(fileName);
    file >> readLine;
    //convert string to a int
    numOfWindows = stoi(readLine);
    cout << "numOfWindows: "<< numOfWindows << endl;
    ptr_windows = new int[numOfWindows];
    // initialize to zero, indicating that they are available and that no one is waiting
    for( int i = 0; i < numOfWindows; ++i)
    {
      ptr_windows[i] = 0;
    }
  // stu- pointer to Student
  Student *stu;
  int countNumberOfStudents = 0;
  // TODO: Later add to condition -> while the queue is not EMPTY.
  while(!file.eof())
  {
    // read an arrival record
      // read time entered queue
      // read # of students
      // read time at window of each student in an inner loop
    cout << "Record " << recordNumber << endl;
    // clear the readline string for a new record; this might be an EMPTY string
    // at the end of the file (after the last record).
    // If such an empty string is found break out of the loop
    readLine = "";
    file >> readLine;
    if(readLine.empty()){
      break;
    }
    studentTimeEnteredQueue = stoi(readLine);
    file >> readLine;

    numOfStudents = stoi(readLine);
    for(int i = 0; i < numOfStudents; ++i)
    {
      file >> readLine;
      waitTime = stoi(readLine);
      //Student *stu = new Student(waitTime,studentTimeEnteredQueue);
      stu = new Student(waitTime,studentTimeEnteredQueue);
      studentRecords->insertBack(*stu);
      cout << "printing: " << *stu << endl;
      countNumberOfStudents++;
      cout << "Diag: # of students: " << countNumberOfStudents << endl;
      //TODO: fix not reading in the newline
    }
    // if the link list time is the timeenteredQueue, put into the queue
    recordNumber++;

  }
  //cout << "Total number of lines: " << keepTrackOfLine << endl;
file.close();

#if 0
// Diag
  cout << "Diag: " << endl;
  studentRecords->printList();
  //GenQueue *myQueue;
  cout << "top: " << studentRecords->peek()<< endl;
  //*stu = studentRecords->timeEnteredQueue;
  cout << "time to enter queue: " << stu->timeEnteredQueue << endl;
  cout << "Time: " << stu->getTimeEnteredQueue() << endl;
  cout << "waitTime: " << studentRecords->peek().timeEnteredQueue << endl;
cout << endl;
# endif
cout << endl;
cout << "Diag: Big while loop" << endl;
int trackCurrentStudentTimeAtWindow = 0;
// average
double meanStudentWaitTime = 0;
// median
float medianStudentWaitTime = 0;
// longest student wait time
int longestStudentWaitTime = 0;
// number of students waiting over 10 minutes
int numStudentsWaitingOver10Minutes = 0;
// total window idle time
int totalWindowIdleTime = 0;
// mean window idle time
int meanWindowIdleTime = 0;
// longest mean window idle time
int longestmeanWindowIdleTime = 0;
// number of windows idle over 5 minutes
int numberOfwindowsIdleOver5Minutes = 0;
// holds the window idle time
int windowIdletime = 0;
// an array that holds window wait time (time spent in queue) of each student
int arr_studentWindowWaitTime[countNumberOfStudents];
for(int j = 0; j < countNumberOfStudents; ++j)
{
   arr_studentWindowWaitTime[j] = 0;
}
int i = 0;
int arr_windowIdleTime[numOfWindows];
int maxIdleTime = 0;
//cout << "numOfWindows: " << numOfWindows << endl;
// initialize all elements to 0
for(int j = 0; j < numOfWindows; ++j)
{
  arr_windowIdleTime[j] = 0;
}
// 1 in array element indicates window has been idle for more than 5 minutes at
// least once. 0 indicates the window has never been idle for more than 5 minutes
// The sum of the array elements is the number of windows that have been idle for
// more than 5 minutes at least once.
int arr_windowIdleForMorethan5Min[numOfWindows];
for( int j = 0; j < numOfWindows; ++j)
{
  arr_windowIdleForMorethan5Min[j] = 0;
}

GenQueue *queue = new GenQueue();
Student student;
int keepTrackOfNumWindows = 0;
unsigned int totalTimeSpentInQueue = 0;

//stop the simulation (break out of the loop) when the queue is empty and there
// are no students pending (studentRecords lists is empty) and all windows are
// idle. (This means that all students have been completely processed and the
// simulation is over).
while(!studentRecords->isEmpty() || !queue->isEmpty() ||
      !allWindowIdle(ptr_windows, numOfWindows))
{
  cout << endl << ">>> CLOCK TICK LOOP: clockTick <<< " << clockTick << endl;
  // /////////////////////////////////////////////////
  // Extracts students from the linked lists
  // (which was populated from reading the file)
  // at the proper clocktick (when they are to enter
  // the queue) and insert them into the queue.
  // ////////////////////////////////////////////////

   while(!studentRecords->isEmpty() &&
     clockTick == studentRecords->peek().timeEnteredQueue)
   {
     cout << "Diag: put student on queue at clockTick: " << clockTick << endl;
     // note: this is temporary on the stack
      student = studentRecords->removeFront();
     //dynamically allocate a student object so that it stays around
     Student*ptr_student = new Student(student.waitTimeAtWindow, student.timeEnteredQueue);
     queue->push_back(*ptr_student);
     queue->print();
   }
   // /////////////////////////////////////////////////
   // Check to if window is available and pop student
   // off queue and assign to window if so
   // ////////////////////////////////////////////////

   // while there's an open window
   // pop off queue
   cout << "here" << endl;
   cout << ">>> Assigning students to Windows <<< " << endl;
   cout << ">>> Number of windows: " << numOfWindows << endl;
   keepTrackOfNumWindows = 0;
   while(!queue->isEmpty() &&
         keepTrackOfNumWindows < numOfWindows)
   {
     cout << ">>> Checking if window " << keepTrackOfNumWindows << " is avialable" << endl;
     if(ptr_windows[keepTrackOfNumWindows] == 0)
     {
       cout << "Assiging student to open window: " << keepTrackOfNumWindows << endl;
       student = queue->pop_front();
       ptr_windows[keepTrackOfNumWindows] = student.waitTimeAtWindow;
       cout << "window: " << keepTrackOfNumWindows << " minute(s): "<< ptr_windows[keepTrackOfNumWindows] << endl;
       // /////////////////////////////////////////////////
       // Update the total time spent in queue (to be used
       // in computing the average wait time in the queue)
       // ////////////////////////////////////////////////
       unsigned int timeSpentInQueue = clockTick - student.timeEnteredQueue;
       //MyChanges: calc the number of student who waited in queue over 10 minutes
       if(timeSpentInQueue > 10)
       {
         numStudentsWaitingOver10Minutes++;
       }
       //MyChanges: find the longest student wait time.
       if(timeSpentInQueue > longestStudentWaitTime)
       {
         longestStudentWaitTime = timeSpentInQueue;
       }
       //MyChanges: calc The median student wait time
       // create an array based on the size of the number of students
       // create a function: pass in the timeSpentInQueue
       // append the timeSpentInQueue to the array
       // Have the function sort the array in asending order and find the median
       arr_studentWindowWaitTime[i] = timeSpentInQueue;
       i++;
       cout << "MY I: " << i << endl;
       totalTimeSpentInQueue += timeSpentInQueue;
       cout << "timeSpentInQueue: " << timeSpentInQueue << endl;
       cout << "totalTimeSpentInQueue: " << totalTimeSpentInQueue << endl;
     }
     keepTrackOfNumWindows++;
   }
   cout << "DIAG: Window Wait Times at clockTick: " << clockTick << endl;
   for( int i = 0; i < numOfWindows; ++i)
   {
     cout << "Window[" << i << "]:" << ptr_windows[i] << endl;
   }

   // /////////////////////////////////////////////////
   // decrement window wait times by one clock tick
   // down to at most zero(zero indicates that the
   // window is open)
   // make sure it doesn't go below zero
   // ////////////////////////////////////////////////
   cout << endl;
   cout << "Decrementing window time" << endl;

   for( int i = 0; i < numOfWindows; ++i)
   {
     if(ptr_windows[i] != 0)
     {
       ptr_windows[i] = ptr_windows[i] - 1;
       cout << "Window_Decrement_"<< i << ":" << ptr_windows[i]<< endl;
       cout << "Window is not idle. Resetting idle time to 0" << endl;
       arr_windowIdleTime[i] = 0;
      }
      //MyChanges: find the total window idle time
      else
      {
        // if its idle then increment the window's idle time
        arr_windowIdleTime[i]++;
        if(arr_windowIdleTime[i] > maxIdleTime)
        {
          maxIdleTime = arr_windowIdleTime[i];
        }
        if(arr_windowIdleTime[i] > 5)
        {
          arr_windowIdleForMorethan5Min[i] = 1;
        }
        totalWindowIdleTime++;
      }
   }


   cout << "printing queue at time: " << clockTick << endl;
   queue->print();
   cout << "Linked List of pending students size: " << studentRecords->getSize() << endl;
   cout << "Queue size: " << queue->getSize() << endl;

   //int stop = 0;
   //cin >> stop;
   cout << ">>> Bottom of Clock Loop <<< " << endl;
   clockTick++;
}
// /////////////////////////////////////////////////
// simulation has ended
// compute average waitTime in queue
// which equals totalTimeSpentInQueue/#numOfStudents
// ////////////////////////////////////////////////
// print queue
cout << endl;
cout << "Time spent in queue: " << totalTimeSpentInQueue<< endl;
cout << "Num of Students: " << countNumberOfStudents << endl;
meanStudentWaitTime = (double)totalTimeSpentInQueue/(double)countNumberOfStudents;
cout << ">> Mean waitTime in queue: " << meanStudentWaitTime << endl;
cout << ">> Number of students waiting over 10 minutes: " << numStudentsWaitingOver10Minutes<< endl;
cout << ">> Longest student wait time: "<< longestStudentWaitTime << endl;
cout << "total window idle time: " << totalWindowIdleTime << endl;
cout << "number of windows: " << numOfWindows << endl;
meanWindowIdleTime = totalWindowIdleTime/numOfWindows;
cout << ">> Mean window idle time: " << meanWindowIdleTime << endl;
for ( int j = 0; j < countNumberOfStudents; j++)
{
  cout << "Student Window Wait Time: " << arr_studentWindowWaitTime[j]<< endl;
}
sortArray(arr_studentWindowWaitTime, countNumberOfStudents);
medianStudentWaitTime = findMedianStudentWaitTime(arr_studentWindowWaitTime, countNumberOfStudents);
cout << ">> Median Student Wait: " << medianStudentWaitTime << endl;
cout << ">> Longest window idle time: "<< maxIdleTime << endl;

for( int i = 0; i < numOfWindows; ++i)
{
  if(arr_windowIdleForMorethan5Min[i] == 1)
  {
     numberOfwindowsIdleOver5Minutes++;
  }
}
cout << ">> Number of windows idle for more than 5 minutes: " << numberOfwindowsIdleOver5Minutes << endl;

//#endif

}

#if 1
float findMedianStudentWaitTime(int arr[], int size)
{
  int position = 0;
  float studentMedianWaitTime = 0;
  //to return the median, check to see if size is an even number or not
  // if its odd, all we have to do is half the size by 2
  if(size%2 == 0)
  {
    studentMedianWaitTime = (arr[(size-1)/2] + arr[size/2])/2.0;
  }
  // odd
  else
  {
    position = size/2;
    studentMedianWaitTime = arr[position];
  }

}
#endif
void sortArray(int *arr, int size)
{
  int temp = 0;
  for( int i = 0; i < size; ++i)
  {
    for(int j = 0; j < size-1; j++)
    {
      if(arr[j]>arr[j+1])
      {
         temp = arr[j];
         arr[j] = arr[j+1];
         arr[j+1] = temp;
      }
    }
  }
  cout << "array sorted" << endl;
  for( int i = 0; i < size; ++i)
  {
     cout << "arr[" << i << "]: " << arr[i] << endl;
  }
}

bool allWindowIdle(int *arr_window, int size)
{
  bool allIdle = true;
  for(int i = 0; i < size; ++i){
    if(arr_window[i] != 0)
    {
      allIdle = false;
    }
  }
  return allIdle;
}
