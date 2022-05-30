# Installing packages

    su root
    apt update && apt install unattended-upgrades
    dpkg-reconfigure unattended-upgrades


# Configuration tweaks

## Edit /etc/apt/apt.conf.d/50unattended-upgrades:

Uncomment the "updates" and "proposed-updates" origin patterns
    
    "origin=Debian,codename=${distro_codename}-updates";
    "origin=Debian,codename=${distro_codename}-proposed-updates";
    "origin=Debian,codename=${distro_codename},label=Debian";
    "origin=Debian,codename=${distro_codename},label=Debian-Security";
    "origin=Debian,codename=${distro_codename}-security,label=Debian-Security";

Add an email address for email notifiction of update activity

    Unattended-Upgrade::Main "user@example.com";

Allow automatically removing unused kernel-related packages

    Unattended-Upgrade::Remove-Unused-Kernel-Packages "true";
    
Allow autmoatically removing unused dependencies

    Unattended-Upgrade::Remove-New-Unused-Dependencies "true";
    
Allow automatically removing unused packages

    Unattended-Upgrade::Remove-Unused-Dependencies "true";
    
Allow automatic reboot

    Unattended-Upgrade::Automatic-Reboot "true";

Unless users normally use the server, allow reboot when users are logged in

    Unattended-Upgrade::Automatic-Reboot-WithUsers "true";
    
Reboot at a specific time (e.g., 4 am)

    Unattended-Upgrade::Automatic-Reboot-Time "04:00";
    
Enable logging to syslog

    Unattended-Upgrade::SyslogEnable "true";

## Create/edit /etc/apt/apt.conf.d/20auto-upgrades:

    /sbin/dpkg-reconfigure --priority=low unattended-upgrades

When asked to "Automatically download and install stable updtes?", answer yes.  

Edit 20auto-upgrades (values are in number of days):

    APT::Periodic::Update-Package-Lists "1";
    APT::Periodic::Download-Upgradeable-Packages "1";
    APT::Periodic::Unattended-Upgrade "1";
    APT::Periodic::AutocleanInterval "3";

# Configure email sending
See server_email_config.md

# Testing
Dry run

    unattended-upgrade -v -d --dry-run
    
Execute

    unattended-upgrade -v -d
