# Installation
As root:

    apt install tor
    tor --version

# Basic Usage
As non-root:

View external IP address.

    wget -qO - https://api.ipify.org; echo
    torsocks wget -qO - https://api.ipify.org; echo

To turn Tor on for this shell session:

    source torsocks on

To turn Tor on for every shell session, add the following to .bashrc:

    echo ".torsocks on" >> ~/.bashrc

To turn Tor off:

    source torsocks off

# Additional configuration
To enable the Tor control port, first create a password, then add it to the Tor config (as root):

    torpass=$(tor --hash-password "mysupersecretpassword")
    printf "HashedControlPassword $torpass\nControlPort 9051\n" | tee -a /etc/tor/torrc
    tail -2 /etc/tor/torrc
    systemctl restart tor

# Additional usage
Example of getting a new external IP:

    echo -e 'AUTHENTICATE "mysupersecretpassword"\r\nsignal NEWNYM\n\nQUIT' | nc 127.0.0.1 9051

To configure Firefox to use Tor, in Firefox settings set manual proxy configuration to SOCKS HOST: localhost and select SOCKSv5.
