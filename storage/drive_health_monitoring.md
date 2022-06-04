# Drive health monitoring
Quick setup instructions for monitoring the health of drives (e.g., spinning rust).  (Debian 11).

# Depenencies
As root:
    apt install smartmontools
    
# Checking for SMART capabilties
Identify the drive to check with `lsblk`.
Check for SMART support with `/sbin/smartctl -i /dev/sdX | grep support`.

# Configuration
These steps assume notification email support has been configured on the machine (e.g. msmtp).

Replace the DEVICESCAN line in /etc/smartd.conf, explicitly adding the drives that should be monitored.
Replace the default `-m root` to `-m desiredemailuser@desiredemaildomain.tld` to enable email monitoring.

Examples (this example schedules an Offline Immediate Test on Saturday at 1am, see ```man smartd.conf``` for more options):

    /dev/sdb -d removable -n standby -H -l error -l selftest -f -s (O/../../6/1) -m desiredemailuser@desiredemaildomain.tld -M exec /usr/share/smartmontools/smartd-runner
    /dev/sdc -d removable -n standby -H -l error -l selftest -f -s (O/../../6/1) -m desiredemailuser@desiredemaildomain.tld -M exec /usr/share/smartmontools/smartd-runner

    
If SMART monitoring within a virtual machine (e.g., USB drive passthrough, or SATA controller passthrough), modify /etc/systemd/system/smartd.service, commenting out the line ```# ConditionVirtualization=no``` to allow SMART monitoring within virtual machines (e.g. with device passthrough), and inform systemd with ```systemctl daemon-reload```. 


# Testing
Modify the DEVICESCAN line in /etc/smartd.conf to include `-M test` at the end of the line, and restart the daemon to test.

    systemctl restart smartmontools

Remove when successful email notification is received, and restart smartmontools again.
