# Configure X-Content-Type header
Enable X-Content-Type header to stop the browser from trying to MIME sniff the content type and force to use declared content-type.

## In Apache
### Enable the headers module

    sudo a2enmod headers
    
### Add Header directive in the virtual host configuration

    <VirtualHost ...
        Header append X-Content-Type-Options nosniff
    </VirtualHost>
    
### Restart apache

    sudo systemctl restart apache2
    
### Test with curl

    curl --head <the site>
    
