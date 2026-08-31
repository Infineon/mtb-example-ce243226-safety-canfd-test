# XMC&trade;: Safety Test Library (STL) for CAN FD

This code example demonstrates the use of the ModusToolbox&trade; Safety Test Library (MTB STL) to test the CAN FD peripheral of the MCU using the internal loopback feature.

Name | Vanity URL
-----|-----------
**Getting started documents** |
ModusToolbox&trade; tools package installation guide| https://www.infineon.com/ModusToolboxInstallguide
ModusToolbox&trade; tools package release notes| https://www.infineon.com/ModusToolboxReleaseNotes
ModusToolbox&trade; tools package quick start guide | https://www.infineon.com/ModusToolboxQSG
ModusToolbox&trade; tools package user guide| https://www.infineon.com/ModusToolboxUserguide
**IDE documents** |
Eclipse IDE for ModusToolbox&trade; user guide | https://www.infineon.com/MTBEclipseIDEUserguide
Visual Studio Code for ModusToolbox&trade; user guide | https://www.infineon.com/MTBVSCodeUserGuide
Arm&reg; Keil&reg; µVision&reg; for ModusToolbox&trade; user guide | https://www.infineon.com/MTBuVisionUserGuide
IAR Embedded Workbench for ModusToolbox&trade; user guide | https://www.infineon.com/MTBIARUserGuide
Configurators and tools |
**General tools** |
ModusToolbox&trade; Dashboard user guide | https://www.infineon.com/ModusToolboxDashboard
ModusToolbox&trade; Project Creator user guide | https://www.infineon.com/ModusToolboxProjectCreator
ModusToolbox&trade; Library Manager user guide | https://www.infineon.com/ModusToolboxLibraryManager
ModusToolbox&trade; BSP Assistant user guide | https://www.infineon.com/ModusToolboxBSPAssistant
ModusToolbox&trade; LCS Manager CLI user guide | https://www.infineon.com/ModusToolboxLCSManager
**BSP configurators** |
ModusToolbox&trade; Device Configurator user guide| https://www.infineon.com/ModusToolboxDeviceConfig
ModusToolbox&trade; CAPSENSE&trade; Configurator user guide | https://www.infineon.com/ModusToolboxCapSenseConfig
ModusToolbox&trade; CAPSENSE&trade; Tuner user guide | https://www.infineon.com/ModusToolboxCapSenseTuner
ModusToolbox&trade; QSPI Configurator user guide | https://www.infineon.com/ModusToolboxQSPIConfig
ModusToolbox&trade; Smart I/O Configurator user guide | https://www.infineon.com/ModusToolboxSmartIOConfig
**Library configurators** |
ModusToolbox&trade; Bluetooth&reg; Configurator user guide | https://www.infineon.com/ModusToolboxBLEConfig
ModusToolbox&trade; EZ-PD&trade; Configurator user guide | https://www.infineon.com/ModusToolboxEZ-PDConfig
ModusToolbox&trade; LIN Configurator user guide | https://www.infineon.com/ModusToolboxLINConfig
ModusToolbox&trade; Secure Policy Configurator user guide | https://www.infineon.com/ModusToolboxSecurePolicyConfig
ModusToolbox&trade; Segment LCD Configurator user guide | https://www.infineon.com/ModusToolboxSegLCDConfig
ModusToolbox&trade; USB Configurator user guide | https://www.infineon.com/ModusToolboxUSBConfig
**MCU tools** |
ModusToolbox&trade; Device Firmware Update Host tool guide | https://www.infineon.com/ModusToolboxDFUHostTool
**Webpage Links** |
ModusToolbox&trade; product page | https://www.infineon.com/ModusToolbox
ModusToolbox&trade; Video Hub | https://www.infineon.com/ModusToolboxVideos
ModusToolbox&trade; Latest Community Announcement Post | https://www.infineon.com/ModusToolboxReleaseAnnouncement

[View this README on GitHub.](https://github.com/Infineon/mtb-example-ce243226-safety-canfd-test)

[Provide feedback on this code example.](https://yourvoice.infineon.com/jfe/form/SV_1NTns53sK2yiljn?Q_EED=eyJVbmlxdWUgRG9jIElkIjoiQ0UyNDMyMjYiLCJTcGVjIE51bWJlciI6IjAwMi00MzIyNiIsIkRvYyBUaXRsZSI6IlhNQyZ0cmFkZTs6IFNhZmV0eSBUZXN0IExpYnJhcnkgKFNUTCkgZm9yIENBTiBGRCIsInJpZCI6ImphaW4uam9zZXBoQGluZmluZW9uLmNvbSIsIkRvYyB2ZXJzaW9uIjoiMS4wLjAiLCJEb2MgTGFuZ3VhZ2UiOiJFbmdsaXNoIiwiRG9jIERpdmlzaW9uIjoiTUNEIiwiRG9jIEJVIjoiSUNXIiwiRG9jIEZhbWlseSI6IlBTT0MifQ==)


## Requirements

- [ModusToolbox&trade;](https://www.infineon.com/modustoolbox) v3.8 or later (tested with v3.8)
- Programming language: C
- Associated parts: [XMC5000 MCU](https://www.infineon.com/products/microcontroller/32bit-industrial-arm-cortex-m/xmc5000)


## Supported toolchains (make variable 'TOOLCHAIN')

- GNU Arm&reg; Embedded Compiler v14.2.1 (`GCC_ARM`) – Default value of `TOOLCHAIN`
- Arm&reg; Compiler v6.22 (`ARM`)
- IAR C/C++ Compiler v9.60.1 (`IAR`)


## Supported kits (make variable 'TARGET')

- [XMC5200 Evaluation Kit](https://www.infineon.com/evaluation-board/KIT-XMC52-EVK) (`KIT_XMC52_EVK`)


## Hardware setup

This example uses the board's default configuration. See the kit user guide to ensure that the board is configured correctly.

The CAN FD self-test uses channel 0 of the CAN FD block with the internal loopback test mode enabled. No external CAN transceiver or wiring is required.


## Software setup

See the [ModusToolbox&trade; tools package installation guide](https://www.infineon.com/ModusToolboxInstallguide) for information about installing and configuring the tools package.

Install a terminal emulator if you do not have one.


## Using the code example


### Create the project

The ModusToolbox&trade; tools package provides the Project Creator as both a GUI tool and a command line tool.

<details><summary><b>Use Project Creator GUI</b></summary>

1. Open the Project Creator GUI tool

   There are several ways to do this, including launching it from the dashboard or from inside the Eclipse IDE. For more details, see the [Project Creator user guide](https://www.infineon.com/ModusToolboxProjectCreator) (locally available at *{ModusToolbox&trade; install directory}/tools_{version}/project-creator/docs/project-creator.pdf*)

2. On the **Choose Board Support Package (BSP)** page, select a kit supported by this code example. See [Supported kits](#supported-kits-make-variable-target)

   > **Note:** To use this code example for a kit not listed here, you may need to update the source files. If the kit does not have the required resources, the application may not work

3. On the **Select Application** page:

   a. Select the **Application(s) Root Path** and the **Target IDE**

      > **Note:** Depending on how you open the Project Creator tool, these fields may be pre-selected for you

   b. Select this code example from the list by enabling its check box

      > **Note:** You can narrow the list of displayed examples by typing in the filter box

   c. (Optional) Change the suggested **New Application Name** and **New BSP Name**

   d. Click **Create** to complete the application creation process

</details>


<details><summary><b>Use Project Creator CLI</b></summary>

The 'project-creator-cli' tool can be used to create applications from a CLI terminal or from within batch files or shell scripts. This tool is available in the *{ModusToolbox&trade; install directory}/tools_{version}/project-creator/* directory.

Use a CLI terminal to invoke the 'project-creator-cli' tool. On Windows, use the command-line 'modus-shell' program provided in the ModusToolbox&trade; installation instead of a standard Windows command-line application. This shell provides access to all ModusToolbox&trade; tools. You can access it by typing "modus-shell" in the search box in the Windows menu. In Linux and macOS, you can use any terminal application.

The following example clones the "[CAN FD test](https://github.com/Infineon/mtb-example-ce243226-safety-canfd-test)" application with the desired name "CANFD_Test" configured for the *KIT_XMC52_EVK* BSP into the specified working directory *C:/mtb_projects*:

   ```
   project-creator-cli --board-id KIT_XMC52_EVK --app-id mtb-example-ce243226-safety-canfd-test --user-app-name CANFD_Test --target-dir "C:/mtb_projects"
   ```

The 'project-creator-cli' tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--board-id` | Defined in the <id> field of the [BSP](https://github.com/Infineon?q=bsp-manifest&type=&language=&sort=) manifest | Required
`--app-id`   | Defined in the <id> field of the [CE](https://github.com/Infineon?q=ce-manifest&type=&language=&sort=) manifest | Required
`--target-dir`| Specify the directory in which the application is to be created if you prefer not to use the default current working directory | Optional
`--user-app-name`| Specify the name of the application if you prefer to have a name other than the example's default name | Optional

<br>

> **Note:** The project-creator-cli tool uses the `git clone` and `make getlibs` commands to fetch the repository and import the required libraries. For details, see the "Project creator tools" section of the [ModusToolbox&trade; tools package user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at {ModusToolbox&trade; install directory}/docs_{version}/mtb_user_guide.pdf).

</details>


### Open the project

After the project has been created, you can open it in your preferred development environment.


<details><summary><b>Eclipse IDE</b></summary>

If you opened the Project Creator tool from the included Eclipse IDE, the project will open in Eclipse automatically.

For more details, see the [Eclipse IDE for ModusToolbox&trade; user guide](https://www.infineon.com/MTBEclipseIDEUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mt_ide_user_guide.pdf*).

</details>


<details><summary><b>Visual Studio (VS) Code</b></summary>

Launch VS Code manually, and then open the generated *{project-name}.code-workspace* file located in the project directory.

For more details, see the [Visual Studio Code for ModusToolbox&trade; user guide](https://www.infineon.com/MTBVSCodeUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mt_vscode_user_guide.pdf*).

</details>


<details><summary><b>Arm&reg; Keil&reg; µVision&reg;</b></summary>

Double-click the generated *{project-name}.cprj* file to launch the Keil&reg; µVision&reg; IDE.

For more details, see the [Arm&reg; Keil&reg; µVision&reg; for ModusToolbox&trade; user guide](https://www.infineon.com/MTBuVisionUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mt_uvision_user_guide.pdf*).

</details>


<details><summary><b>IAR Embedded Workbench</b></summary>

Open IAR Embedded Workbench manually, and create a new project. Then select the generated *{project-name}.ipcf* file located in the project directory.

For more details, see the [IAR Embedded Workbench for ModusToolbox&trade; user guide](https://www.infineon.com/MTBIARUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mt_iar_user_guide.pdf*).

</details>


<details><summary><b>Command line</b></summary>

If you prefer to use the CLI, open the appropriate terminal, and navigate to the project directory. On Windows, use the command-line 'modus-shell' program; on Linux and macOS, you can use any terminal application. From there, you can run various `make` commands.

For more details, see the [ModusToolbox&trade; tools package user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>


## Operation

1. Connect the board to your PC using the provided USB cable through the KitProg3 USB connector

2. Open a terminal program and select the KitProg3 COM port. Set the serial port parameters to 8N1 and 115200 baud

3. Program the board using one of the following:

   <details><summary><b>Using Eclipse IDE</b></summary>

      1. Select the application project in the Project Explorer

      2. In the **Quick Panel**, scroll down, and click **\<Application Name> Program (KitProg3_MiniProg4)**
   </details>


   <details><summary><b>In other IDEs</b></summary>

   Follow the instructions in your preferred IDE

   </details>


   <details><summary><b>Using CLI</b></summary>

     From the terminal, execute the `make program` command to build and program the application using the default toolchain to the default target. The default toolchain is specified in the application's Makefile but you can override this value manually:
      ```
      make program TOOLCHAIN=<toolchain>
      ```

      Example:
      ```
      make program TOOLCHAIN=GCC_ARM
      ```
   </details>

4. After programming, the application starts automatically. Confirm that "MTB STL: CAN FD Safety Test" is displayed on the UART terminal

5. The serial terminal should display the result of the test

   **Figure 1. Terminal output on program startup**

   ![](images/terminal-canfd-test.png)


## Debugging

You can debug the example to step through the code.


<details><summary><b>In Eclipse IDE</b></summary>

Use the **\<Application Name> Debug (KitProg3_MiniProg4)** configuration in the **Quick Panel**. For details, see the "Program and debug" section in the [Eclipse IDE for ModusToolbox&trade; user guide](https://www.infineon.com/MTBEclipseIDEUserGuide).

</details>


<details><summary><b>In other IDEs</b></summary>

Follow the instructions in your preferred IDE.

</details>


## Design and implementation

This example uses the CAN FD peripheral on the MCU to perform a self-test of the CAN FD channel. The *design.modus* file configures channel 0 of the CAN FD block (RX FIFO0/FIFO1 depth set to 4 elements each, 64-byte buffer data field size).

The example begins by initializing the BSP configuration and setting up retarget-io for debug prints over the dedicated debug UART. The CAN FD channel (channel 0) is then initialized: the MRAM is enabled, the channel is configured via `Cy_CANFD_Init()`, and the channel interrupt is hooked and enabled. On this MCU, the CAN FD channel interrupt is a system interrupt that must be routed through an NVIC MUX slot to reach the CPU, so `Cy_SysInt_Init()` is used with the interrupt source built from the NVIC MUX channel and the CAN FD IRQ number.

A self-test is then run using the `SelfTest_CANFD()` API from the mtb-stl (https://github.com/Infineon/mtb-stl) safety library. The library reconfigures the channel into internal loopback test mode, transmits a frame with an ID outside the configured acceptance filter range (verifying it is correctly rejected), then transmits a frame with an ID inside the acceptance filter range and verifies it is received in the RX FIFO with matching data. Because the CAN FD channel is taken over for the duration of the test, it cannot run concurrently with real CAN bus traffic - this is the same constraint that applies to other communication peripheral self-tests (SPI, I2C, UART) in this library. The function returns a single final result (no repeated calls needed). The PASS or FAIL result is printed to the debug UART console, and the device halts after a single complete run.

See the application notes listed in [Related resources](#related-resources) for more details.


### Resources and settings

**Table 1. Application resources**

 Resource  |  Alias/object     |    Purpose
 :-------- | :-------------    | :------------
 UART (HAL) | DEBUG_UART | UART HAL object used by retarget-io for the Debug UART port
 CAN FD (PDL) | CYBSP_CANFD | CAN FD channel 0 under test (internal loopback)

<br>

## Related resources

Resources  | Links
-----------|----------------------------------
Application notes  | [AN241720](https://www.infineon.com/assets/row/public/documents/30/42/infineon-getting-started-with-xmc5000-mcu-on-modustoolbox-software-applicationnotes-en.pdf) – Getting started with XMC5000 MCU on ModusToolbox&trade; <br>
Code examples | [Using ModusToolbox&trade;](https://github.com/Infineon/Code-Examples-for-ModusToolbox-Software) on GitHub
Device documentation | [XMC5000 MCU documents](https://www.infineon.com/products/microcontroller/32bit-industrial-arm-cortex-m/xmc5000#Documents) <br>
Development kits | Select your kits from the [Evaluation board finder](https://www.infineon.com/cms/en/design-support/finder-selection-tools/product-finder/evaluation-board)
Libraries on GitHub  | [mtb-pdl-cat1](https://github.com/Infineon/mtb-pdl-cat1) – Peripheral Driver Library (PDL) <br> [mtb-hal-cat1](https://github.com/Infineon/mtb-hal-cat1) – Hardware Abstraction Layer (HAL) Library
Middleware on GitHub | [mcu-middleware](https://github.com/Infineon/modustoolbox-software) – Links to all MCU middleware <br> [mtb-stl](https://github.com/Infineon/mtb-stl) - Safety Test Library (STL)
Tools  | [ModusToolbox&trade;](https://www.infineon.com/modustoolbox) – ModusToolbox&trade; software is a collection of easy-to-use libraries and tools enabling rapid development with Infineon MCUs for applications ranging from wireless and cloud-connected systems, edge AI/ML, embedded sense and control, to wired USB connectivity using PSOC&trade; Industrial/IoT MCUs, AIROC&trade; Wi-Fi and Bluetooth&reg; connectivity devices, XMC&trade; Industrial MCUs, and EZ-USB&trade;/EZ-PD&trade; wired connectivity controllers. ModusToolbox&trade; incorporates a comprehensive set of BSPs, HAL, libraries, configuration tools, and provides support for industry-standard IDEs to fast-track your embedded application development

<br>

## Other resources

Infineon provides a wealth of data at [www.infineon.com](https://www.infineon.com) to help you select the right device, and quickly and effectively integrate it into your design.


## Document history

Document title: *CE243226* – *XMC&trade;: Safety Test Library (STL) for CAN FD*

 Version | Description of change
 ------- | ---------------------
 1.0.0   | New code example

<br>


All referenced product or service names and trademarks are the property of their respective owners.

The Bluetooth&reg; word mark and logos are registered trademarks owned by Bluetooth SIG, Inc., and any use of such marks by Infineon is under license.

PSOC&trade;, formerly known as PSoC&trade;, is a trademark of Infineon Technologies. Any references to PSoC&trade; in this document or others shall be deemed to refer to PSOC&trade;.

---------------------------------------------------------

(c) 2026, Infineon Technologies AG, or an affiliate of Infineon Technologies AG. All rights reserved.
This software, associated documentation and materials ("Software") is owned by Infineon Technologies AG or one of its affiliates ("Infineon") and is protected by and subject to worldwide patent protection, worldwide copyright laws, and international treaty provisions. Therefore, you may use this Software only as provided in the license agreement accompanying the software package from which you obtained this Software. If no license agreement applies, then any use, reproduction, modification, translation, or compilation of this Software is prohibited without the express written permission of Infineon.
<br>
Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A SPECIFIC USE/PURPOSE OR MERCHANTABILITY. Infineon reserves the right to make changes to the Software without notice. You are responsible for properly designing, programming, and testing the functionality and safety of your intended application of the Software, as well as complying with any legal requirements related to its use. Infineon does not guarantee that the Software will be free from intrusion, data theft or loss, or other breaches ("Security Breaches"), and Infineon shall have no liability arising out of any Security Breaches. Unless otherwise explicitly approved by Infineon, the Software may not be used in any application where a failure of the Product or any consequences of the use thereof can reasonably be expected to result in personal injury.
