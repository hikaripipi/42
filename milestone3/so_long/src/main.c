/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikarimac <hikarimac@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:45:09 by hikarimac         #+#    #+#             */
/*   Updated: 2025/07/22 20:26:34 by hikarimac        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main(int argc, char **argv)
{
    int fd;  // ← まず変数を宣言

    if (argc != 2)
    {
        printf("Error: Usage: %s <map.ber>\n", argv[0]);
        return (1);
    }

    printf("Map file: %s\n", argv[1]);
    
    fd = open(argv[1], O_RDONLY);  // ← ファイルを開く
    
    if (fd < 0)
        printf("Error: Cannot open file\n");
    else
        printf("File opened successfully!\n");

	char buffer[1000];  // 十分大きなバッファ
	int bytes_read;

	bytes_read = read(fd, buffer, 999);
	buffer[bytes_read] = '\0';  // 文字列の終端

	printf("Read %d bytes:\n", bytes_read);
	printf("Content:\n%s", buffer);
        
    close(fd);  // ← ファイルを閉じる
    
    return (0);  // ← 最後にreturn
}
