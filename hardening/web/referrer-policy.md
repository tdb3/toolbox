# Configure Referrer-Policy header
Enable Referrer-Policy header to control how much information the browser includes with navigations away.

## In Apache
### Enable the headers module

    sudo a2enmod headers
    
### Add Header directive in the virtual host configuration

    <VirtualHost ...
        Header always set Referrer-Policy "same-origin"
    </VirtualHost>

See https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Referrer-Policy for list of directives, so the appropriate directive can be set for the site.

### Restart apache

    sudo systemctl restart apache2
    
### Test with curl

    curl --head <the site>
    
