<div align="center">
  <h1> Simple DLL Injection with <b> C </b> </h1>
  <img src="https://github.com/devTBenoth/DLL-Injector/blob/main/gif/video.gif" />
</div> <br/>
<p>
   Welcome to my simple DLL Injection Project written in C! This project injects a DLL into any running Process. <br/>
   When a DLL is injected into the program, a message called DLL Injected is printed on the screen.
</p> 

<h2> Running Program </h2>
<b>1-</b> First of all, copy the dll file in the dll_file to the C: location. <br> <br>
<b>2-</b> Then compile the cpp project: <br> <br>

```sh
gcc injector.cpp -o injector
``` 
<br>
<b> 3-</b> Then run the program: <br> <br>

```sh
.\injector <PID>
```
