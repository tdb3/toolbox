### User and key creation
Create a new user on the machine hosting the service (which performs the persistent forwarding), become the user, and generate an SSH key pair.

    adduser portforwarder
    su portforwarder
    cd
    ssh-keygen -t ecdsa

### Install the systemd service
Install the systemd service file (cp to /etc/systemd/system/, or the applicable systemd directory for the distro), and enable.

    cp systemd/portforwarder.service /etc/systemc/system/
    systemctl daemon-reload
    systemctl start
    systemctl status
    systemctl enable
