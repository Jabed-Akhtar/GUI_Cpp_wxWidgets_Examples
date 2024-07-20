### App#1: Hello World
### App#2: Ctrls, Styles & Events
### App#3: ToDo List - Simple

# Project steps
### Step#1: Download wxWidgets
- Download from: [https://www.wxwidgets.org/](https://www.wxwidgets.org/)
- wxWidget used here: wxWidgets-3.2.5

> i. Download 'Window ZIP (Source Code)'  
> ii. Keep the source code at a location

### Step#2: Add *wxWidgets* path to 'Environment Variables'  
> i. Goto 'System Properties' > 'Environment Variables' > 'System variables' > 'New...'  
> ii. 'Variable name:' WXWidgets_WIN, 'Variable value:' <path-to-wxWidgets>  

### Step#3: Build *wxWidgets* for MS-windows
> i. Go to directory <wxWidgets-root-dir>/build/msw/  
> ii. Open (double click) on solution, e.g.: wx_vc16.sln for VS-2019  
> iii. Build for Debug-Win32, Release-Win32, Debug-x64, and Release-x64. Choose all these four configs one-by-one and build from 'Build > Build solution'  
>> 32 bit libraray is saved at location <wxWidgets-root-dir>/lib/vc_lib/  
>> 64 bit libraray is saved at location <wxWidgets-root-dir>/lib/vc_x64_lib/  

### Step#4: Open Project solution and Run
