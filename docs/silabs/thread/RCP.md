# How to Build and Flash the Radio Co-Processor (RCP)

The Radio Co-Processor is a 15.4 stack image flashed onto a Silicon Labs
development kit or Thunderboard Sense 2. The 15.4 stack on the development kit
communicates with the higher layers of the Thread stack running on the Raspberry
Pi over a USB connection.

A complete list of supported hardware for the RCP is provided on the
[Matter Hardware Requirements](../general/HARDWARE_REQUIREMENTS.md) page.

First, in order to flash the RCP, connect it to your laptop directly by USB.

<br>

## Step 1: Get or Build the Image File to Flash the RCP

We have provided two ways to get the required image to flash the RCP. You can
use one of the following options:

1. Use the pre-built 'ot-rcp' image file
2. Build the image file from the 'ot-efr32' repository, which is listed on the
   [Matter Repositories and Commit Hashes page](../general/COMMIT_HASHES.md)

<br>

### **Using a Pre-built Image File**

RCP image files for all demo boards are accessible through the
[Matter Artifacts Page](../general/ARTIFACTS.md). If you are using a pre-built
image file, you can skip to [Step #2: Flash the RCP](#step-2-flash-the-rcp).

<br>

### **Building the Image File from the ot-efr32 Repository**

**1. Clone the ot-efr32 repository**

The 'ot-efr32' repo is located in Github here:
https://github.com/SiliconLabs/ot-efr32.

You must have Git installed on your local machine. To clone the repo use the
following command:

```shell
$ git clone https://github.com/SiliconLabs/ot-efr32.git
```

Once you have cloned the repo, enter the repo and sync all the submodules with
the following command:

```shell
$ cd ot-efr32
```

```shell
$ git submodule update --init
```

After updating the submodules you can check out the correct branch or commit
hash for the system. Check the current branch and commit hash used here:
[Matter Branches and Commit Hashes](../general/COMMIT_HASHES.md)

```shell
$ git checkout <commit hash>
```

<br>

**2. Build the RCP**

Once you have checked out the correct hash, follow the instructions here:
https://github.com/SiliconLabs/ot-efr32/blob/main/src/README.md to build the RCP
image for your EFR platform.

This process will build several images for your board. The filename of the image
to be flashed onto the board to create an RCP is 'ot-rcp.s37'.

The output of the build process puts all the image files in the following
location: '<git>/ot-efr32/build/<efr32xgxx>'

<br>

## Step 2: Flash the RCP

Once you get the RCP image, either by downloading a prebuilt image or building
the image file, you can flash it onto your device. This is done
directly from your laptop and not through the Raspberry Pi, so make sure that
the device is connected directly over USB to your laptop. See
[How to Flash a Silicon Labs Device](../general/FLASH_SILABS_DEVICE.md) for more information.

Once you have flashed the image, the device becomes the RCP. Disconnect it from
you laptop and connect it via USB to the Raspberry Pi.

The Raspberry Pi's Open Thread Border Router can then use the RCP to communicate
with the Thread network.

## Troubleshooting

To run the Mattertool, you need the OTBR to be running. To check the OTBR status, *enter sudo systemctl status otbr-agent* on the Raspberry Pi console.

A successfully running OTBR will show the output below:

```shell
pi@raspberrypi:~ $ sudo systemctl status otbr-agent
● otbr-agent.service - OpenThread Border Router Agent
     Loaded: loaded (/lib/systemd/system/otbr-agent.service; enabled; vendor preset: enabled)
     Active: active (running) since Mon 2024-03-04 09:09:44 EST; 1 weeks 2 days ago
```

You can restart the OTBR agent by entering *sudo systemctl restart otbr-agent*.

If the OTBR agent is restarting continuously, it's likely because it cannot connect to the RCP. There are multiple reasons that can contribute to this:

Ensure that RCP has been configured correctly:

- The RCP has a default UART baudrate of 115200.
- If using a Wireless Gecko Starter Kit (WSTK), make sure the WSTK baud is configured correctly:

   1. Open the WSTK console in Simplicity Studio by right clicking on the device under **Debug Adapters**.
   2. Select the **Admin** tab in the console.
   3. Configure the RCP with `serial vcom config <'baud rate'>`.

- Make sure the RCP has been flashed with a bootloader image.
- Make sure the RCP GSDK version matches the OTBR GSDK version.