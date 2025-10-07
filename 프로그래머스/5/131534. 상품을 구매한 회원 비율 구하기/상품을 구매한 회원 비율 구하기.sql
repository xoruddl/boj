select 
    YEAR(sales_date) as YEAR,
    MONTH(sales_date) as MONTH,
    COUNT(DISTINCT(ui.user_id)) as PURCHASED_USERS,
    ROUND(COUNT(DISTINCT ui.user_id) / (SELECT COUNT(user_id) 
                                        FROM user_info
                                        WHERE YEAR(JOINED) = '2021')
         , 1) AS PUCHASED_RATIO
from 
    online_sale os
left join
    user_info ui 
on 
    ui.user_id = os.user_id
where  
    YEAR(ui.joined) = '2021'
group by
    YEAR(sales_date),
    MONTH(sales_date)
order by
    YEAR ASC,
    MONTH ASC;
    
    