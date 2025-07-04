# BASED ON THE BLUE PILL SPI EXTERNAL FLASH LOADER.
#	At the first need send many thanks to Controllerstech which explain this subject on the him YT channel:

https://www.youtube.com/watch?v=Gil_LbT5UVw

![Screenshot](/PICTURES/00_CONTROLLERSTECH.jpg)
First you need make new STM32 project for STM32F103C8T6 and don’t forgot about exist 2 blue pills – old blue pill and new blue pill PLUS. Which can have W25Qxx SPI FLASH on board. Also if you want blinking led it have LED on the PC13 for old blue pill. New blue pill PLUS got the led on PB2.

* - FLASH is connected to SPI1:
* PA4 as CS/
* PA5 as SPI1 CLK
* PA6 as SPI1 MISO (GPIO INPUT PIN)
* PA7 as MOSI

![Screenshot](/PICTURES/01_W25QXX.jpg)

So let create a new STM32 project for STM32F103C8T6 and enable RCC:
![Screenshot](/PICTURES/02_RCC.jpg)

Enable Debug Serial Wire in SYS section.
![Screenshot](/PICTURES/03_SYS.jpg)

Now set the system clock:
![Screenshot](/PICTURES/04_CLOCK.jpg)

And enable SPI1:
![Screenshot](/PICTURES/05_SPI1.jpg)

Enable PA4, PB2 and PC13 as GPIO Output:
![Screenshot](/PICTURES/06_PINOUT.jpg)

Set the User labels for this 3 pin as follow:
![Screenshot](/PICTURES/07_GPIO.jpg)

In Project Manager set the genrate peripherial initializations files as pair c/h:
![Screenshot](/PICTURES/08_PROJECT_MANAGER.jpg)

And generate project.
* Now you need copy 6 files into the project.
* Into the root folder copy file:
* linker.ld
* Into the inc folder:
* Dev_Inf.h
* W25Qxx.h
* Into the src folder:
* Dev_Inf.c
* Loader_Src.c
* W25Qxx.c

![Screenshot](/PICTURES/09_COPY.jpg)

Now need add a few changes in **main.c** file:
![Screenshot](/PICTURES/10_text.jpg)

![Screenshot](/PICTURES/11_text.jpg)

![Screenshot](/PICTURES/12_text.jpg)

For minimize output file and **cheating** compiler:
![Screenshot](/PICTURES/13_text.jpg)

Last one in **main.c** not mandatory – when loader working this code never reaching this point.
![Screenshot](/PICTURES/14_text.jpg)

In the **linker.ld** file need only one change to do:
![Screenshot](/PICTURES/15_linker.jpg)

In the **W25Qxx.h** file take care about this lines for 2MB flash:
![Screenshot](/PICTURES/16_W25Qxx_h.jpg)

For **Dev_Inf.c** file need change:
![Screenshot](/PICTURES/17_Dev_Inf_c.jpg)

In file **W25Qxx.c** two changes for led blinking under work external SPI flash loader:
![Screenshot](/PICTURES/18_W25Qxx_c.jpg)

![Screenshot](/PICTURES/19_W25Qxx_c.jpg)

After all of this from hammer icon choose release build:
![Screenshot](/PICTURES/20_setup.jpg)

The loader should be build like bellow:
![Screenshot](/PICTURES/21_setup.jpg)

In Project->Properties->C/C++ Build->Settings->Build Steps->Post-build steps->Command:
Put the command like:
cmd.exe /C copy /Y "${BuildArtifactFileBaseName}.elf" "..\W25Q_BLUEPILL_F103_EL_2MB.stldr"

![Screenshot](/PICTURES/22_setup.jpg)
And click Apply  and Close buton.

In Project->Properties->C/C++ Build->Settings->Tool Settings->MCU/MPU GCC Linker->General
Make sure the „Discard unused sections (-Wl, --gcc-sections)” is checked for make smallest as possibility output execute file.

![Screenshot](/PICTURES/23_setup.jpg)
And click Apply  and Close buton.

In Project->Properties->C/C++ Build->Settings->Tool Settings->MCU/MPU GCC Compiler->Optimization
Make sure the Optimization level is set to: „Optimize for size (-Os)” is choosed for make smallest as possibility output execute file.

![Screenshot](/PICTURES/24_setup.jpg)
And click Apply  and Close buton.

In Project->Properties->C/C++ Build->Settings->Tool Settings->MCU/MPU GCC Linker->General
In the Linker Script (-T) text edit  field put the text:
 ${workspace_loc:/${ProjName}/linker.ld}
Which choose our linker.ld file.

![Screenshot](/PICTURES/25_linker_file.jpg)
And click Apply  and Close buton.

Now from menu Project choose Clean option, and after this choose Build Project option. What should gave final effect:

![Screenshot](/PICTURES/26_FINAL.jpg)

At the end you need copy the stldr file int the ST-Link Utility or STM32CubeProgrammer folder for external loaders.

![Screenshot](/PICTURES/27_copy_EL.jpg)

After this you can use this external loader when you choose him in EL menu.
