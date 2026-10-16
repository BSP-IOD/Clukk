@"
                Clukk
             Release V3.0
             
                XB2B
"@

Write-Host "1. Kilobytes (KB) to Bytes."
Write-Host "2. Megabytes (MB) to Bytes."
$choice = Read-Host "Select (1/2)"
Write-Host ""

if ($choice -eq '1') {
    $kb = [float](Read-Host "Enter amount of KB")
    $bytes_val = $kb * 1024
    Write-Host "$kb KB converted to bytes: $([int]$bytes_val):N0}."
}
elseif ($choice -eq '2') {
    $mb = [float](Read-Host "Enter amount of MB")
    $bytes_val = $mb * 1024 * 1024
    Write-Host "$mb MB converted to bytes: $([int]$bytes_val):N0}."
}
else {
    Write-Host "Error."
}
