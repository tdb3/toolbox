# Configure Permissions-Policy header
Enable Permissions-Policy header to tell the browser what features and APIs can be used in the browser.

## In Apache
### Enable the headers module

    sudo a2enmod headers
    
### Add Header directive in the virtual host configuration

    <VirtualHost ...
        Header always set Permissions-Policy "accelerometer=(), ambient-light-sensor=(), autoplay=(), battery=(), camera=(), cross-origin-isolated=(), display-capture=(), document-domain=(), encrypted-media=(), execution-while-not-rendered=(), execution-while-out-of-viewport=(), fullscreen=(), geolocation=(), gyroscope=(), keyboard-map=(), magnetometer=(), microphone=(), midi=(), navigation-override=(), payment=(), picture-in-picture=(), publickey-credentials-get=(), screen-wake-lock=(), sync-xhr=(self), usb=(), web-share=(), xr-spatial-tracking=()"
    </VirtualHost>

See https://www.permissionspolicy.com/ for a list of policy features, and to customize for hte site being hardened.
    
### Restart apache

    sudo systemctl restart apache2
    
### Test with curl

    curl --head <the site>
    
