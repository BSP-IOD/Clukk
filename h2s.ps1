@"
                Clukk
             Release V2.3
             
                 H2S
"@
Write-Host ""
$hours = [float](Read-Host "Enter amount of hours")
$seconds = $hours * 60 * 60
Write-Host "Hours converted to seconds: $seconds"
