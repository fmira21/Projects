# Blockchain parsers

## ethparser.py

The parser using the Ethplorer API to find all ERC-20 tokens on addresses, a list of which is uploaded into a script in the `.xlsx` format as the first argument.

### Dependencies

The parser requires an API endpoint containing all tokens supported by your resource.

Libraries:

* [openpyxl](https://pypi.org/project/openpyxl/)
* [numpy](https://pypi.org/project/numpy/)

### XLSX input format

By default, the script parses addresses from the `D` column of the table.

### Output format

The parser makes a NumPy dictionary with all ERC-20 tokens that have not been found at your endpoint but detected at the input addresses.

## wavesparser.py

This parser is intended for finding the latest transactions in the Waves blockchain from a given address according to their number and version.

To learn more about the Waves transactions, refer to the [official documentation](https://docs.wavesenterprise.com/en/latest/description/transactions/tx-description.html).

### Usage:

1. Choose data you are going to look for.

    To find a transaction acording to its number and version, execute the following comand:

    ```bash
    python3 wavesparser.py <Tx type> <Tx version>
    ```

    To find a transaction of all versions, execute:

    ```bash
    python3 wavesparser.py <Tx type>
    ```

    To find all transactions of the same version, execute:

    ```bash
    python3 wavesparser.py <Tx version>
    ```

2. Upon a request, enter the Waves blockchain address.

3. Upon a request, enter the transaction limit. The default limit is 400 latest transactions at the address.