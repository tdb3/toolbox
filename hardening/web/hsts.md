# Enable HSTS
Enable HTTP Strict Transport Security to prevent downgrade to HTTP.

## In Apache
### Enable the headers module

    sudo a2enmod headers
    
### Add Header directive in the virtual host configuration

    <VirtualHost ...
        Header always set Strict-Transport-Security "max-age=31536000;includeSubDomains"
    </VirtualHost>
    
### Restart apache

    sudo systemctl restart apache2
    
### Test with curl

    curl --head <the site>
    
