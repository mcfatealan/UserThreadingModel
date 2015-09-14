# UserThreadingModel
A simple model to simulate user-threading programs, it contains a data race

`thread.c` is a thread package from <http://homepage.cs.uiowa.edu/~jones/opsys/threads/>, which is for creating a simple non-preemptive user-threading program.

`main.c` is a sample program written by me. As you see, **thread_singer** and **thread_snoozer** will be running alternately (If you set the param to be 0, **thread_singer** will stop printing and perform an empty loop).

There's an obvious data race in **race_var**. But there's no possibilities that Valgrind could detect it because it's not a multi-threading program. If we could detect this race, detecting race in UML would be realistic.

One more thing, in this model we have to insert **thread_relinquish()** to allow other threads have chance to run. It's a little bit different from what UML does. Actually it seems there's no much material talking about kernel thread context switching in UML. Maybe we just made wrong guesses before. Please check this link about some process knowledge of UML.  <http://user-mode-linux.sourceforge.net/old/skas.html>

But I believe the key point has been made.
