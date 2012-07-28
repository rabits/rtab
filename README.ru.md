rTab - Годный Табулатурный Редактор
===================================

_Все проблемы и предложения, связанные с rTab можно обсудить на [Issues Page](https://github.com/rabits/rplay/issues)_

## Предпосылки

*Кросс-платформенный табулатурный редактор, ориентированный на MeeGo 1.2 Harmattan (Nokia N9)*

## Поддержать разработку

Если вы захотели поддержать разработку - это очень просто сделать при помощи Яндекс.Деньги или PayPal!

[Yandex.Money: 410011493978798](https://money.yandex.ru/donate.xml?to=410011493978798)
[PayPal](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&encrypted=-----BEGIN PKCS7-----MIIHJwYJKoZIhvcNAQcEoIIHGDCCBxQCAQExggEwMIIBLAIBADCBlDCBjjELMAkGA1UEBhMCVVMxCzAJBgNVBAgTAkNBMRYwFAYDVQQHEw1Nb3VudGFpbiBWaWV3MRQwEgYDVQQKEwtQYXlQYWwgSW5jLjETMBEGA1UECxQKbGl2ZV9jZXJ0czERMA8GA1UEAxQIbGl2ZV9hcGkxHDAaBgkqhkiG9w0BCQEWDXJlQHBheXBhbC5jb20CAQAwDQYJKoZIhvcNAQEBBQAEgYBTFGFeNAg9e%2B3PPyOeaRZkNtpbu67aERV%2FdhWf%2FuJfHmUq%2FvuFKnk%2BC7SMssRoBzplsP4ULWFjpRPbQsBE0DU77AliCVUq6P%2FXyvwE15Pf4ToMphiCnpWGSa72bTOef%2FGW0LnzECt2Wsc33E3l0uqXKHe1%2BQDRUcuoR8blmwFmWjELMAkGBSsOAwIaBQAwgaQGCSqGSIb3DQEHATAUBggqhkiG9w0DBwQIAala9eWcRviAgYAv%2BTerpsTwakmU%2BTbC%2FtBLDNhwZUVdhZb60Hbb%2BfNTxXZ02itsCJdbEJR7OLa5KnBBB7oWnVaHvF8JTFLIwneO%2F0mkr8yTS8OhE9tU55ksc7VLxEW4JHUMDQAp6prBz%2F4FnhFabapYfFCJhT5ptacRN40v4PLhy5E95Scv%2FFtVrqCCA4cwggODMIIC7KADAgECAgEAMA0GCSqGSIb3DQEBBQUAMIGOMQswCQYDVQQGEwJVUzELMAkGA1UECBMCQ0ExFjAUBgNVBAcTDU1vdW50YWluIFZpZXcxFDASBgNVBAoTC1BheVBhbCBJbmMuMRMwEQYDVQQLFApsaXZlX2NlcnRzMREwDwYDVQQDFAhsaXZlX2FwaTEcMBoGCSqGSIb3DQEJARYNcmVAcGF5cGFsLmNvbTAeFw0wNDAyMTMxMDEzMTVaFw0zNTAyMTMxMDEzMTVaMIGOMQswCQYDVQQGEwJVUzELMAkGA1UECBMCQ0ExFjAUBgNVBAcTDU1vdW50YWluIFZpZXcxFDASBgNVBAoTC1BheVBhbCBJbmMuMRMwEQYDVQQLFApsaXZlX2NlcnRzMREwDwYDVQQDFAhsaXZlX2FwaTEcMBoGCSqGSIb3DQEJARYNcmVAcGF5cGFsLmNvbTCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEAwUdO3fxEzEtcnI7ZKZL412XvZPugoni7i7D7prCe0AtaHTc97CYgm7NsAtJyxNLixmhLV8pyIEaiHXWAh8fPKW%2BR017%2BEmXrr9EaquPmsVvTywAAE1PMNOKqo2kl4Gxiz9zZqIajOm1fZGWcGS0f5JQ2kBqNbvbg2%2FZa%2BGJ%2FqwUCAwEAAaOB7jCB6zAdBgNVHQ4EFgQUlp98u8ZvF71ZP1LXChvsENZklGswgbsGA1UdIwSBszCBsIAUlp98u8ZvF71ZP1LXChvsENZklGuhgZSkgZEwgY4xCzAJBgNVBAYTAlVTMQswCQYDVQQIEwJDQTEWMBQGA1UEBxMNTW91bnRhaW4gVmlldzEUMBIGA1UEChMLUGF5UGFsIEluYy4xEzARBgNVBAsUCmxpdmVfY2VydHMxETAPBgNVBAMUCGxpdmVfYXBpMRwwGgYJKoZIhvcNAQkBFg1yZUBwYXlwYWwuY29tggEAMAwGA1UdEwQFMAMBAf8wDQYJKoZIhvcNAQEFBQADgYEAgV86VpqAWuXvX6Oro4qJ1tYVIT5DgWpE692Ag422H7yRIr%2F9j%2FiKG4Thia%2FOflx4TdL%2BIFJBAyPK9v6zZNZtBgPBynXb048hsP16l2vi0k5Q2JKiPDsEfBhGI%2BHnxLXEaUWAcVfCsQFvd2A1sxRr67ip5y2wwBelUecP3AjJ%2BYcxggGaMIIBlgIBATCBlDCBjjELMAkGA1UEBhMCVVMxCzAJBgNVBAgTAkNBMRYwFAYDVQQHEw1Nb3VudGFpbiBWaWV3MRQwEgYDVQQKEwtQYXlQYWwgSW5jLjETMBEGA1UECxQKbGl2ZV9jZXJ0czERMA8GA1UEAxQIbGl2ZV9hcGkxHDAaBgkqhkiG9w0BCQEWDXJlQHBheXBhbC5jb20CAQAwCQYFKw4DAhoFAKBdMBgGCSqGSIb3DQEJAzELBgkqhkiG9w0BBwEwHAYJKoZIhvcNAQkFMQ8XDTEyMDcyNzEwMjA0NVowIwYJKoZIhvcNAQkEMRYEFJcWjjo%2FAWEMNTSr7bEacgIzotypMA0GCSqGSIb3DQEBAQUABIGAJciJcvQGE12cUmSY7SnE17e3yhtxx8hhsXC8qwFF5Wejy2scxUKT0pShK%2BZsHiZe26B6yVamBOX6wcWGhFYqw7tOjQd%2Fqp8aIIQaycVoja7sq99NkUUC5iZQWT3ztOcjGfW9Fk0RaCZfsJD8lrKoTGU7mQnvzYFwEfVxMdjT%2B4Q%3D-----END PKCS7-----%0A)

## Планы:
### v1.0 - Просмотрщик

 * Поддержка интерфейса для Линукс-десктопа и Nokia N9
 * Поддержка форматов .gpx и .tg
 * Просмотр табулатур
 * Выбор текущего трека
 * Горизонтальный скроллинг

### v2.0 - Проигрыватель

 * Поддержка Windows платформы
 * Движок для проигрывания треков
 * Импорт MIDI, .gp5, .gp4 и .gp3
 * Гриф
 * Автоматический скроллинг во время проигрывания
 * Поиск табулатур в интернете
 * Собственный формат (с поддержкой репозиториев и diff-утилиты)
 * Удобное сравнивание различий в композициях

### v3.0 - Редактор

 * Инструменты для создания и редактирования композиций
 * Сохранение в форматах .gpx и .tg
 * Экспорт в gp5 и midi форматы
 * Поддержка клавиатурной раскладки GuitarPro и цифрового редактирования ударных

## Благодарности

От всего сердца хотел бы поблагодарить разработчиков [TuxGuitar](http://www.tuxguitar.com.ar/). Без этого проекта я бы не смог начать разработку.

## Автор

 * Rabit < home.rabits@gmail.com >

## Сайты

 * [GitHub/rTab](https://github.com/rabits/rtab)
 * [Rabit.sru](http://rabits.ru)

## Лицензия: GNU GPLv3

    rTab is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see http://www.gnu.org/licenses/ .
