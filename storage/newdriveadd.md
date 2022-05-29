### Adding an additional drive
(Debian)

#### Identify the drive's device file (e.g. /dev/sdb).  

    lsblk

#### Create the parition

    /sbin/fdisk /dev/sdX
    g (create GUID parition table)
    n (create new partition)
    w (write and quit)

#### Format the partition

    /sbin/mkfs.ext4 /dev/sdX1

#### Create a directory for mounting the drive.

    DRIVEDIR=driveX
    mkdir /mnt/$DRIVEDIR

#### Mount the drive and identify the UUID of the drive (example with sdb1)

    DRIVEDEV=sdb1
    mount /dev/$DRIVEDEV /mnt/$DRIVEDIR
    DRIVEUUID=$(/sbin/blkid | grep $DRIVEDEV | cut -d' ' -f2 | cut -d'=' -f2 | sed -e 's/"//g')
    echo $DRIVEUUID

(Vet the drive UUID against /sbin/blkid output)  

#### Create an fstab entry, so the drive is mounted on boot

    echo "" >> /etc/fstab
    echo "# Added to mount $DRIVEDIR" >> /etc/fstab
    echo "/dev/disk/by-uuid/$DRIVEUUID /mnt/$DRIVEDIR auto nosuid,nodev,nofail 0 0" >> /etc/fstab
    
(For fstab options and syntax, https://help.ubuntu.com/community/Fstab)

Reboot the host/VM, and check that the drive is mounted on boot in /mnt/driveX.
