@"
                Clukk
             Release V2.3
             
                URL2IP
"@
Write-Host ""
$ip = Read-Host "Enter URL"
$x = (Resolve-DnsName $ip).IPAddress[0]
Write-Host "IP: $x"
