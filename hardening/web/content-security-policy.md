# Configure Content-Security-Policy header
Enable Content-Security-Policy header to control whitelisting sources of approved content (prevent loading of malicious assets).

## In Apache
### Enable the headers module

    sudo a2enmod headers
    
### Add Header directive in the virtual host configuration

    <VirtualHost ...
        Header set Content-Security-Policy "default-src 'none'; img-src 'self'; media-src 'self'; script-src 'self'; style-src 'self'; font-src 'self' data:; object-src 'self'; base-uri 'self'; connect-src 'self'; form-action 'self'; frame-ancestors 'self'"
    </VirtualHost>

See https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Content-Security-Policy so the appropriate directives can be set for the site.

### Restart apache

    sudo systemctl restart apache2
    
### Test with curl

    curl --head <the site>
    
