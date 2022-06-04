# Configure X-Frame-Options header
Enable X-Frame-Options header to tell the browser that we don't want to allow the site to be framed.

## In Apache
### Enable the headers module

    sudo a2enmod headers
    
### Add Header directive in the virtual host configuration

    <VirtualHost ...
        Header append X-Frame-Options: "SAMEORIGIN"
    </VirtualHost>
    
### Restart apache

    sudo systemctl restart apache2
    
### Test with curl

    curl --head <the site>
    
