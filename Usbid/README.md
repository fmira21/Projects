# Logger of connected  USB devices

USBID is a script able to detect and log USB devices connected to a PC. With the use of USBID, you can display all devices connected to a particular PC, add them to your log (whitelist) and define if a device is whitelisted or not.

## Dependencies

* [pyusb](https://pypi.org/project/pyusb/):

```bash
pip3 install pyusb
```

## Usage

To run the script, execute the command:

```bash
python3 usbid.py
```

Possible menu entries:

* `new` - create new log and add (whitelist) all connected devices.
* `accept` - add (whitelist) all connected devices to the existing `usblog.txt`.
* `show` - display all connected devices in the terminal.
* `check` - check if connected devices are in the `usblog.txt` or not.

If no devices are connected, the script returns an exception for each of the entries.

## Log syntax

The log containing all whitelisted devices consists of the mapped entries `Vendor ID : Device ID` in the hexadecimal format:

```bash
0x1210 : 0x25f4
```

## Workflow

To keep your infrastructure clear from unallowed USB devices:

1. Connect all allowed USB devices 
2. Start the script and `accept` the devices. After this, you will have a complete whitelist in the `usblog.txt`.
3. Backup the whitelist with the use of the `new` command by saving the same log under the other name.
4. If you need to check if any device is whitelisted, connect it to any machine and `check` it with your `usblog.txt` in the script folder.
5. If you have lost or corrupted your `usblog.txt`, rename the backup file to `usblog.txt` and proceed.