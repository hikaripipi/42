/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshinaga <hshinaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:36:43 by hshinaga          #+#    #+#             */
/*   Updated: 2025/04/29 21:40:38 by hshinaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
    t_node *a = create_node(1);
    a->next = create_node(2);
    a->next->next = create_node(3);

    sa(&a); // 1と2を入れ替える

    // 確認用に1番上のノードの値だけ出力
    char buf[12];
    int len = sprintf(buf, "%d\n", a->value);
    write(1, buf, len);

    return 0;
}